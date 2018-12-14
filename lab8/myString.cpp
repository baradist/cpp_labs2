#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "myString.h"

void Swap(MyString &left, MyString &right) {
    Counter *tmp = left.m_pMyCounter;
    left.m_pMyCounter = right.m_pMyCounter;
    right.m_pMyCounter = tmp;
}

void MyString::printAll() {
    Counter *cur = Counter::Head;
    while (cur) {
        std::cout << *cur << std::endl;
        cur = cur->pNext;
    }
    std::cout << std::endl;
}

void MyString::uppercaseAll() {
    Counter *cur = Counter::Head;
    while (cur) {
        for (size_t i = 0; i < strlen(cur->m_pStr); i++) {
            cur->m_pStr[i] = toupper(cur->m_pStr[i]);
        }
        cur = cur->pNext;
    }
}

MyString::MyString() : m_pMyCounter(Counter::find("")) {
}

MyString::MyString(const MyString &that) : m_pMyCounter(that.m_pMyCounter) {
    m_pMyCounter->addUser();
}

MyString::MyString(MyString &&that) : m_pMyCounter(that.m_pMyCounter) {
    that.m_pMyCounter = nullptr;
}

MyString::MyString(const char *str) : m_pMyCounter(Counter::find(str)) {
}

MyString::~MyString() {
    if (m_pMyCounter) {
        m_pMyCounter->removeUser();
    }
    m_pMyCounter = nullptr;
}

bool MyString::operator==(const MyString &that) {
    return m_pMyCounter == that.m_pMyCounter;
}

MyString &MyString::operator=(MyString &&that) {
    if (m_pMyCounter != that.m_pMyCounter) {
        if (m_pMyCounter != nullptr) {
            m_pMyCounter->removeUser();
        }
        m_pMyCounter = that.m_pMyCounter;
        that.m_pMyCounter = nullptr;
    }
    return *this;
}

MyString &MyString::operator=(const MyString &that) {
    if (m_pMyCounter == that.m_pMyCounter) {
        return *this;
    }
    m_pMyCounter->removeUser();
    m_pMyCounter = that.m_pMyCounter;
    m_pMyCounter->addUser();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const MyString &myString) {
    return os << *myString.m_pMyCounter;
}

void MyString::sort() {
    Counter::Head = Counter::sort(Counter::Head, Counter::m_curCounters);
}

bool MyString::startsWith(const char c) const {
    if (m_pMyCounter == nullptr) {
        return false;
    }
    return toupper(c) == toupper(m_pMyCounter->m_pStr[0]);
}

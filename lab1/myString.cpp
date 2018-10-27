#include <string>
#include <cstring>
#include "myString.h"

using namespace std;

// Определение конструктора.
MyString::MyString() {
    SetNewValue(nullptr);
}

MyString::MyString(const MyString &myString) {
    SetNewValue(myString.GetString());
}

MyString::MyString(const char *pStr) {
    SetNewValue(pStr);
}

// Определение деструктора.

MyString::~MyString() {
    delete m_pStr;
}

char *MyString::GetString() const {
    return m_pStr;
}

void MyString::SetNewString(const char *pStr) {
    delete m_pStr;
    SetNewValue(pStr);
}

void MyString::SetNewValue(const char *pStr) {
    if (pStr == nullptr) {
        m_pStr = new char[1];
        m_pStr[0] = 0;
    } else {
        int size = strlen(pStr) + 1;
        m_pStr = new char[size];
        strcpy(m_pStr, pStr);
    }
}

MyString concatenateMyStrings(const char *fmt...) {
    const char **p = &fmt;
    size_t size = 0;
    while (*p) {
        size += strlen(*p++);
    }
    char *buf = new char[size + 1];
    buf[0] = 0;
    p = &fmt;
    while (*p) {
        strcat(buf, *p++);
    }
    MyString result(buf);
    delete[] buf;
    return result;
}

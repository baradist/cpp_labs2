#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Counter.h"

Counter *Counter::Head = nullptr;
size_t Counter::m_curCounters = 0;

Counter::Counter(const char *str) : pNext(Head) {
    Head = this;
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
    m_curCounters++;
    m_nOwners = 1;
}

Counter::~Counter() {
    delete[] m_pStr;
    --m_curCounters;

    if (!m_curCounters) {
        Head = nullptr;
        return;
    }
    if (Head == this) {
        Head = pNext; // = Head->pNext
        return;
    }
    Counter *cur = Head;
    while (cur->pNext != this) {
        cur = cur->pNext;
    }
    cur->pNext = pNext; // = cur->pNext->pNext
}

void Counter::addUser() {
    m_nOwners++;
}

void Counter::removeUser() {
    m_nOwners--;
    if (!m_nOwners) {
        delete this;
    }
}

bool Counter::operator==(const char *str) const {
    return !strcmp(m_pStr, str);
}

Counter *Counter::find(const char *str) {
    Counter *cur = Head;
    while (cur) {
        if (*cur == str) {
            cur->addUser();
            return cur;
        }
        cur = cur->pNext;
    }
    return new Counter(str);
}

std::ostream &operator<<(std::ostream &os, const Counter &c) {
    return os << c.m_pStr << ", owners: " << c.m_nOwners;
}

Counter *Counter::sort(Counter *c, size_t size) {
    if (size == 1) {
        return c;
    }
    Counter *last = c;
    size_t newSize = size / 2;
    for (size_t i = 1; i < newSize; i++) {
        last = last->pNext;
    }
    Counter *secondHalf = last->pNext;
    last->pNext = nullptr;

    return Counter::merge(sort(c, newSize),
                          sort(secondHalf, size - newSize));
}

Counter *Counter::merge(Counter *c1, Counter *c2) {
    Counter *result = nullptr;
    if (compare(c1, c2)) {
        result = c1;
        c1 = c1->pNext;
    } else {
        result = c2;
        c2 = c2->pNext;
    }
    Counter *cur = result;

    while (c1 || c2) {
        if (!c1) {
            cur->pNext = c2;
            c2 = c2->pNext;
        } else if (!c2 || compare(c1, c2)) {
            cur->pNext = c1;
            c1 = c1->pNext;
        } else {
            cur->pNext = c2;
            c2 = c2->pNext;
        }
        cur = cur->pNext;
    }
    return result;
}

bool Counter::compare(Counter *c1, Counter *c2) {
    return strcmp(c1->m_pStr, c2->m_pStr) < 0;
}

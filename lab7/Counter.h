#pragma once

#include <iostream>

class Counter {
    friend std::ostream &operator<<(std::ostream &os, const Counter &c);

    Counter *pNext;
    char *m_pStr;
    size_t m_nOwners;

    static Counter *Head;
    static size_t m_curCounters;

    friend class MyString;

    Counter() = default;

    Counter(const char *str);

    ~Counter();

    static Counter *find(const char *str);

    static Counter *sort(Counter *c, size_t size);

    static Counter *merge(Counter *c1, Counter *c2);

    static bool compare(Counter *c1, Counter *c2);

    bool operator==(const char *str) const;

    void addUser();

    void removeUser();
};

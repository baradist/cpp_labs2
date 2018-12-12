#pragma once

#include <iostream>
#include "Counter.h"

class MyString {
    Counter *m_pMyCounter;

    friend void Swap(MyString &left, MyString &right);

public:
    static void printAll();

    static void uppercaseAll();

    static void sort();

    friend std::ostream &operator<<(std::ostream &os, const MyString &c);

    MyString();

    MyString(const MyString &that);

    MyString(MyString &&that);

    MyString(const char *str);

    ~MyString();

    bool operator==(const MyString &that);

    MyString &operator=(MyString &&that);

    MyString &operator=(const MyString &that);
};

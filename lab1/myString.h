#pragma once

#include <cstdarg>

class MyString {
    char *m_pStr;    //строка-член класса

    void SetNewValue(const char *pStr);

public:

    MyString();

    MyString(const MyString &myString);

    MyString(const char *pStr);

    ~MyString();

    const  char *GetString() const;

    void SetNewString(const char *pStr);
};

MyString concatenateMyStrings(const char *fmt...);

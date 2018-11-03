#pragma once

#include <cstdarg>
#include <iostream>

using namespace std;

class MyString {
    char *m_pStr;    //строка-член класса

    void SetNewValue(const char *pStr);

public:

    MyString();

    MyString(const MyString &myString);

	MyString(MyString &&myString);

    MyString(const char *pStr);

    ~MyString();

    char *GetString() const;

    void SetNewString(const char *pStr);

	MyString& operator=(const MyString & that);

	MyString& operator=(const char* str);

	friend ostream& operator<<(ostream& os, const MyString& string);

	MyString & operator+=(const MyString& that);

	MyString operator+(const MyString& that);
};

MyString concatenateMyStrings(const char *fmt...);

ostream& operator<<(ostream& os, const MyString& string);
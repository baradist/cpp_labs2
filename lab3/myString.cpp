#include <string>
#include <cstring>
#include "myString.h"

using namespace std;

// Определение конструктора.
MyString::MyString() {
	m_pStr = new char[1] {0};
}

MyString::MyString(const MyString &that) {
		m_pStr = new char[strlen(that.m_pStr)];
		strcpy(m_pStr, that.m_pStr);
}

MyString::MyString(MyString &&myString) {
	m_pStr = myString.m_pStr;
	myString.m_pStr = new char[1]{ 0 };
}

MyString::MyString(const char *pStr) {
	if (pStr == nullptr) {
		m_pStr = new char[1]{0};
	}
	else {
		m_pStr = new char[strlen(pStr)];
		strcpy(m_pStr, pStr);
	}
}

// Определение деструктора.

MyString::~MyString() {
    //delete m_pStr; // TODO: ??
}

const char *MyString::GetString() const {
    return m_pStr;
}

void MyString::SetNewString(const char *pStr) {
    delete m_pStr;
	if (pStr == nullptr) {
		m_pStr = new char[1] {0};
	}
	else {
		m_pStr = new char[strlen(pStr)];
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

ostream & operator<<(ostream & os, const MyString & str)
{
	os << "Bantiki " << str.m_pStr << " Bantiki";
	return os;
}

MyString & MyString::operator=(const MyString & that) {
	if (this == &that) {
		return *this;
	}
	if (strlen(m_pStr) < strlen(that.m_pStr))
	{
		//delete[] m_pStr; // TODO ???
		m_pStr = new char[strlen(that.m_pStr)+1];
	}
	strcpy(m_pStr, that.m_pStr);
	return *this;
}

MyString & MyString::operator=(MyString && that)
{
	if (this == &that) {
		return *this;
	}
	//delete m_pStr;
	m_pStr = that.m_pStr;
	that.m_pStr = nullptr;

	return *this;
}

MyString & MyString::operator=(const char* str) {
	if (strlen(m_pStr) < strlen(str))
	{
		//delete[] m_pStr; // TODO ???
		m_pStr = new char[strlen(str)+1];
	}
	strcpy(m_pStr, str);
	return *this;
}

MyString & MyString::operator+=(const MyString & that)
{
	size_t newSize = strlen(that.m_pStr) + strlen(m_pStr) + 1;
	char* t = m_pStr;
	m_pStr = new char[newSize];
	strcpy(m_pStr, t);
	strcat(m_pStr, that.m_pStr);
	//delete[] t; // TODO ???
	return *this;
}

MyString MyString::operator+(const MyString & that)
{
	char* pNewString = new char[strlen(m_pStr) + strlen(that.m_pStr) + 1];
	strcpy(pNewString, that.m_pStr);
	strcat(pNewString, that.m_pStr);
	return MyString(pNewString);
}

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

MyString::MyString(MyString &&myString) {
	m_pStr = myString.m_pStr;
	myString.m_pStr = nullptr;
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

ostream & operator<<(ostream & os, const MyString & str)
{
	os << "Бантики " << str.m_pStr << " Бантики";
	return os;
}

MyString & MyString::operator=(const MyString & that) {
	if (this == &that) {
		return *this;
	}
	if (strlen(m_pStr) < strlen(that.m_pStr))
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(that.m_pStr)];
	}
	strcpy(m_pStr, that.m_pStr);
	return *this;
}

MyString & MyString::operator=(const char* str) {
	if (strlen(m_pStr) < strlen(str))
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(str)];
	}
	strcpy(m_pStr, str);
	return *this;
}

MyString & MyString::operator+=(const MyString & that)
{
	size_t newSize = strlen(that.m_pStr) + strlen(m_pStr);
	char* t = m_pStr;
	m_pStr = new char[newSize];
	strcpy(m_pStr, t);
	strcat(m_pStr, that.m_pStr);
	delete[] t;
	return *this;
}

MyString MyString::operator+(const MyString & that)
{
	return MyString(strcat(this->m_pStr, that.m_pStr));
}

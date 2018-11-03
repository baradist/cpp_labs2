#pragma once

#include <iostream>
#include "myString.h"

using namespace std;

enum Gender { MALE, FEMALE };

class Data
{
	Gender gender;
	int age;
	MyString firstName;
	int salary;

public:
	Data();

	Data(int age, Gender, const char* firstName, int salary);

	~Data() = default;

	Data & operator=(const Data & that);

	friend ostream & operator<<(ostream & os, const Data & d);
};

class Pair {
	MyString key; //ключ - фамилия
	Data data; //данные о сотруднике
			   //Подумайте, все ли перечисленные ниже методы надо реализовывать
	Pair() = default;
	Pair(const char *k, const Data& d);
	~Pair() = default;
	Pair(const Pair& other) = default;
	Pair& operator=(const Pair& other) = default;
	Pair(Pair&& other) = default;
	Pair& operator=(Pair&& other) = default;
	bool operator==(const char *k) const; 
	friend class Base;
	friend ostream& operator<<(ostream& os, const Pair& pair);

	friend ostream & operator<<(ostream & os, const Pair & pair);
	//или каких-либо методов не хватает
};

class Base
{
	Pair *pBase; // Pair **pBase; //указатель на базу данных
	size_t count; //количество элементов в базе
	size_t capacity; //емкость базы

public:
	Base();
	virtual ~Base();

	Base(const Base& bd);
	Base& operator=(const Base& bd); //оптимизированный!!!
	Base(Base&& bd);
	Base& operator=(Base&& bd);

	int deletePair(const char* key);

	Data& operator[](const char *key);

	friend ostream& operator<<(ostream& os, const Base& bd);
};

ostream& operator<<(ostream& os, const Base& bd);

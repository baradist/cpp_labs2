#include "bd.h"


Base::Base()
{
	capacity = 10;
	count = 0;
	pBase = new Pair[10];
}

Base::~Base()
{
	delete [] pBase;
}

Base::Base(const Base & bd)
{
	capacity = bd.capacity;
	count = bd.count;
	pBase = new Pair[count];
	for (size_t i = 0; i < count; i++)
	{
		pBase[i] = bd.pBase[i];
	}
}

Base & Base::operator=(const Base & bd)
{
	if (capacity < bd.count)
	{
		capacity = bd.count;
		delete[] pBase;
		pBase = new Pair[capacity];
	}
	
	count = bd.count;
	for (size_t i = 0; i < bd.count; i++) // memcpy - removed
	{
		pBase[i] = bd.pBase[i];
	}
	return *this;
}

Base::Base(Base && bd)
{
	capacity = bd.capacity;
	count = bd.count;
	pBase = bd.pBase;
	bd.pBase = nullptr;
}

Base & Base::operator=(Base && bd)
{
	capacity = bd.count;
	count = bd.count;
	pBase = bd.pBase;
	bd.pBase = nullptr;
	return *this;
}

int Base::deletePair(const char * key)
{
	for (size_t i = 0; i < count; i++) {
		if (pBase[i] == key) // if(*pBase[i] == key)
		{
			for (size_t j = i; j < count - 1; j++) {
				pBase[j] = pBase[j + 1];
			}
			--count;
			return 1;
		}
	}
	return 0;
}

Data& Base::operator[](const char *key)
{
	//ищем сотрудника в базе
	for (size_t i = 0; i < count; i++) {
		if (pBase[i] == key) // if(*pBase[i] == key)
			return pBase[i].data;
	}
	//если сотрудник не найден, добавляем (всегда!!!)
	if(count >= capacity) {
		//перераспределяем память
		
		capacity *= 2;
		Pair* pNewBase = new Pair[capacity];
		for (size_t i = 0; i < count; i++)
		{
			pNewBase[i] = pBase[i];
		}
		delete[] pBase;
		pBase = pNewBase;
	}
	//добавляем сотрудника
	pBase[count] = Pair(key);
	return pBase[count++].data;
}

ostream & operator<<(ostream & os, const Base & bd)
{
	os << "Бантики ";
	for (size_t i = 0; i < bd.count; i++)
	{
		os << bd.pBase[i];
	}
	os << " Бантики" << endl;
	return os;
}

ostream & operator<<(ostream & os, const Pair & pair)
{
	os << pair.key << " " << pair.data;
	return os;
}

ostream & operator<<(ostream & os, const Data & d)
{
	// TODO: gender
	os << (d.gender ? "Female" : "Male") << " " << d.age << " " << d.firstName;
	return os;
}

Data::Data()
{
}

Data::Data(int age, Gender, const char* firstName, int salary): firstName(firstName)
{
	this->age = age;
	//this->firstName = MyString(firstName);
	this->salary = salary;
}

//Data & Data::operator=(const Data & that)
//{
//	if (this == &that) {
//		return *this;
//	}
//	gender = that.gender;
//	age = that.age;
//	salary = that.salary;
//	firstName = that.firstName;
//
//	return *this;
//}

Pair::Pair(const char * k) : key(k)
{
}

Pair::Pair(const char * k, const Data & d):key(k), data(d)
{
}

bool Pair::operator==(const char * k) const
{
	return !strcmp(key.GetString(), k);
}

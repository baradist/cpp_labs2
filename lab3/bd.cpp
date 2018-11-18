#include "bd.h"


Base::Base()
{
	capacity = 10;
	count = 0;
	pBase = new Pair[10];
}

Base::~Base()
{
}

Base::Base(const Base & bd)
{
}

Base & Base::operator=(const Base & bd)
{
	// TODO: ����������������?

	capacity = bd.capacity;
	count = bd.count;
	if (capacity < bd.count)
	{
		delete[] pBase;
		pBase = new Pair[capacity];
	}
	memcpy(pBase, bd.pBase, bd.count);
	return *this;
}

Base::Base(Base && bd)
{
}

Base & Base::operator=(Base && bd)
{
	capacity = bd.capacity;
	count = bd.count;
	if (capacity < bd.count)
	{
		delete[] pBase;
		pBase = new Pair[capacity];
	}
	memcpy(pBase, bd.pBase, bd.count);
	return *this;
}

int Base::deletePair(const char * key)
{
	return 0;
}

Data& Base::operator[](const char *key)
{
	//���� ���������� � ����
	for (size_t i = 0; i < count; i++) {
		if (pBase[i] == key) // if(*pBase[i] == key)
			return pBase[i].data;
	}
	//���� ��������� �� ������, ��������� (������!!!)
	if(count >= capacity) {
		//���������������� ������
		delete[] pBase;
		capacity *= 2;
		pBase = new Pair[capacity];	
	}
	//��������� ����������
	pBase[count] = Pair(key, Data());
	count++;
	return pBase[count].data;
}

ostream & operator<<(ostream & os, const Base & bd)
{
	os << "������� ";
	for (size_t i = 0; i < bd.count; i++)
	{
		os << bd.pBase[i];
	}
	os << " �������" << endl;
	return os;
}

ostream & operator<<(ostream & os, const Pair & pair)
{
	os << pair.key << " " << pair.data;
	return os;
}

ostream & operator<<(ostream & os, const Data & d)
{
	os << d.gender << " " << d.age << " " << d.firstName; // TODO ???
	return os;
}

Data::Data()
{
}

Data::Data(int age, Gender, const char* firstName, int salary)
{
	this->age = age;
	this->firstName = MyString(firstName);
	this->salary = salary;
}

Data & Data::operator=(const Data & that)
{
	if (this == &that) {
		return *this;
	}
	gender = that.gender;
	age = that.age;
	salary = that.salary;

	return *this;
}

Pair::Pair(const char * k, const Data & d):key(k), data(d)
{
}

bool Pair::operator==(const char * k) const
{
	return !strcmp(key.GetString(), k);
}

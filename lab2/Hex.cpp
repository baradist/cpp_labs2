#include <iostream>

#include "Hex.h"

using namespace std;

void Hex::Show() const
{
	cout << static_cast<int>(m_hex0) << static_cast<int>(m_hex1) << dec << endl;
}

void Hex::ShowPos(int intpos) const
{
	switch (intpos)
	{
	case 0:
		cout << m_hex0;
		break;
	case 1:
		cout << m_hex1;
		break;
	default:
		cout << "wrong arg!" << endl;
	}
}

void Hex::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_hex0 = val;
		break;
	case 1:
		m_hex1 = val;
		break;
	}
}

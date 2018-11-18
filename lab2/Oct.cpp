#include <iostream>
#include "Oct.h"

using namespace std;

void Oct::Show() const
{
	cout << static_cast<int>(m_oct0) << static_cast<int>(m_oct1) << static_cast<int>(m_oct2) << endl;
}

void Oct::ShowPos(int intpos) const
{
	switch (intpos)
	{
	case 0:
		cout << static_cast<int>(m_oct0) << endl;
		break;
	case 1:
		cout << static_cast<int>(m_oct1) << endl;
		break;
	case 2:
		cout << static_cast<int>(m_oct2) << endl;
		break;
	default:
		cout << "wrong arg!" << endl;
	}
}

void Oct::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_oct0 = val;
		break;
	case 1:
		m_oct1 = val;
		break;
	case 2:
		m_oct2 = val;
		break;
	default:
		cout << "wrong arg!" << endl;
	}
}

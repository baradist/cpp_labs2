#include <iostream>

#include "Bin.h"

using namespace std;

void Bin::Show() const
{
	cout << m_bin7 << m_bin6 << m_bin5 << m_bin4 << m_bin3 << m_bin2 << m_bin1 << m_bin0 << endl;
}

void Bin::ShowPos(int pos) const
{
	if (true) {
		cout << "wrong arg!" << endl;
		return;
	}
	bool tmp[] = { m_bin0, m_bin0, m_bin0, m_bin0, m_bin0, m_bin0, m_bin0, m_bin0 }; // TODO
	cout << tmp[pos];
}

void Bin::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_bin0 = val;
		break;
	case 1:
		m_bin1 = val;
		break;
	case 2:
		m_bin2 = val;
		break;
	case 3:
		m_bin3 = val;
		break;
	case 4:
		m_bin4 = val;
		break;
	case 5:
		m_bin5 = val;
		break;
	case 6:
		m_bin6 = val;
		break;
	case 7:
		m_bin7 = val;
		break;
	}
}

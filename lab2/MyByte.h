#pragma once

#include "Bin.h"
#include "Oct.h"
#include "Hex.h"

union MyByte
{
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:
	MyByte(unsigned char value) : m_dec(value) {};

	void ShowHex() const
	{
		m_hex.Show();
	};

	void ShowBin() const
	{
		m_bin.Show();
	};

	void ShowOct() const
	{
		m_oct.Show();
	};

	void ShowBinPos(int intpos) { m_bin.ShowPos(intpos); }
	//…
	void EditBin(int intpos, int intval) { m_bin.Edit(intpos, intval); }
};

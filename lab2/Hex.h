#pragma once

class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;

public:
	void Show() const; //выводим все шестнадцатеричные цифры
	void/*int*/ ShowPos(int intpos) const;//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val);//изменяем цифру в позиции
	friend union Bytes;
};

#pragma once

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;
	
public:
	void Show() const;//выводим все восьмеричные цифры
	void/*int*/ ShowPos(int intpos) const;//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val);//изменяем цифру в позиции
	friend union Bytes;
};

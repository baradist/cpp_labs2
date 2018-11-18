#pragma once

class Bin
{
	bool m_bin0 : 1;
	bool m_bin1 : 1;
	bool m_bin2 : 1;
	bool m_bin3 : 1;
	bool m_bin4 : 1;
	bool m_bin5 : 1;
	bool m_bin6 : 1;
	bool m_bin7 : 1;
public:
	void Show() const;//выводим все двоичные цифры
	void/*int*/ ShowPos(int intpos) const;//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
	friend union Bytes;
	//При реализации методов проверьте корректность переданных параметров
	//Используйте потоковый вывод (std::cout)
};

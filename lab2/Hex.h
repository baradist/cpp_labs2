#pragma once

class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;

public:
	void Show() const; //������� ��� ����������������� �����
	void/*int*/ ShowPos(int intpos) const;//������� ����� � �������
	void/*int*/ Edit(int pos, int val);//�������� ����� � �������
	friend union Bytes;
};

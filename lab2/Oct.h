#pragma once

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;
	
public:
	void Show() const;//������� ��� ������������ �����
	void/*int*/ ShowPos(int intpos) const;//������� ����� � �������
	void/*int*/ Edit(int pos, int val);//�������� ����� � �������
	friend union Bytes;
};

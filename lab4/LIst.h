#pragma once

#include "Circle.h"

class Node
{
	//friend class List; // TODO: doesn't work?

	Node* pPrev;
	Node* pNext;
	Circle m_Data;

public:
	Node();
	Node(const Circle * pc);
	Node(Node* prev, Node* next, const Circle * pc);
	~Node();

	void inline setPrev(Node* prev) { pPrev = prev; };
	void inline setNext(Node* next)	{ pNext = next; };
	inline Node* getPrev() {return pPrev;};
	inline Node* getNext() { return pNext; };
	inline Circle* getValue();

}; 

class List
{
	Node* first;
	Node* last;
	unsigned int m_size;
	void unlink(Node* node);
	void merge(const List& that);

	friend ostream& operator<<(ostream& os, const List& l);
	
public:
	List();
	~List();

	void sort();
	
	void addFirst(const Circle& c);
	void addLast(const Circle& c);
	bool remove(const Circle& c);
	int removeAll(const Circle& c);
	Circle get(unsigned int i);
	Circle & operator[](int i);
	int size() const;
	void clear();

};

ostream& operator<<(ostream& os, const List& l);

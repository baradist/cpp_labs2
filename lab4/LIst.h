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

	void setPrev(Node* prev);
	void setNext(Node* next);
	Node* getPrev();
	Node* getNext();
	const Circle* getValue();
}; 

class List
{
	Node *first;
	Node *last;
	unsigned int size;
	void unlink(Node* node);
public:
	List();
	~List();

	void addFirst(const Circle& c);
	void addLast(const Circle& c);
	bool remove(const Circle& c);
};

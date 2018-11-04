#include "LIst.h"


void List::unlink(Node * node)
{
	Node* prev = node->getPrev();
	Node* next = node->getNext();

	if (prev == nullptr) {
		first = next;
	} else {
		prev->setNext(next);
	}
	if (next == nullptr) {
		last = prev;
	} else {
		next->setPrev(prev);
	}
	delete node;
	--size;
}

List::List()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}


List::~List()
{
	delete first;
	delete last;
}

void List::addFirst(const Circle & c)
{
	Node* f = first;
	Node* newNode = new Node(&c);
	newNode->setNext(f);
	first = newNode;
	if (f == nullptr) {
		last = newNode;
	} else {
		f->setPrev(newNode);
	}
	size++;
}

void List::addLast(const Circle & c)
{
	Node* l = last;
	Node* newNode = new Node(&c);
	newNode->setPrev(l);
	last = newNode;
	if (l == nullptr) {
		first = newNode;
	} else {
		l->setNext(newNode);
	}
	size++;
}

bool List::remove(const Circle & c)
{
	Node* cur = first;
	do {
		if (*cur->getValue() == c) {
			unlink(cur);
			return true;
		}
		cur = cur->getNext();
	} while (cur != nullptr);

	return false;
}

Node::Node()
{
}

Node::Node(const Circle * pc)
{
	m_Data = *pc;
}

Node::Node(Node * prev, Node * next, const Circle * pc) : pPrev(prev), pNext(next)
{
	m_Data = *pc;
}

Node::~Node()
{
	pPrev = nullptr;
	pNext = nullptr;
	//delete *m_Data; // TODO???
}

void Node::setPrev(Node * prev)
{
	pPrev = prev;
}

void Node::setNext(Node * next)
{
	pNext = next;
}

Node * Node::getPrev()
{
	return pPrev;
}

Node * Node::getNext()
{
	return pNext;
}

const Circle * Node::getValue()
{
	return &m_Data;
}

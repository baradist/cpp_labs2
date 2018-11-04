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
	--this->size;
}

List::List()
{
	first = nullptr;
	last = nullptr;
	this->size = 0;
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
	++this->size;
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
	++this->size;
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

int List::removeAll(const Circle & c)
{
	size_t count = 0;
	Node* cur = first;
	do {
		if (*cur->getValue() == c) {
			unlink(cur);
			++count;
		}
		cur = cur->getNext();
	} while (cur != nullptr);

	return count;
}

Circle List::get(unsigned int index)
{
	if (index < 0 || index >= this->size)
	{
		return Circle(); // TODO: throw an exception
	}
	Node* cur = first;
	for (size_t i = 0; i < index; i++)
	{
		cur = cur->getNext();
	}
	return Circle(*cur->getValue());
}

int List::size()
{
	return this->size;
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

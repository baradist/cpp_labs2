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
	
	--this->m_size;
}

List::List() : first(nullptr), last(nullptr), m_size(0)
{}


List::~List()
{
	clear();
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
	++this->m_size;
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
	++this->m_size;
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
		Node* next = cur->getNext();
		if (*cur->getValue() == c) {
			unlink(cur);
			++count;

			
			delete cur;
			
		}
		
			cur = next;
		
		
	} while (cur != nullptr);

	return count;
}

Circle List::get(unsigned int index)
{
	return Circle(operator[](index));
}

Circle & List::operator[](int index)
{
	//if (index < 0 || index >= this->m_size)
	//{
	//	return Circle(); // TODO: throw an exception
	//}
	Node* cur = first;
	for (size_t i = 0; i < index; i++)
	{
		cur = cur->getNext();
	}
	return *(cur->getValue());
}

int List::size() const
{
	return this->m_size;
}

void List::clear()
{
	Node* cur = first;
	Node* next;
	while (cur != nullptr) {
		next = cur->getNext();
		delete cur;
		cur = next;
	}
	first = nullptr;
	last = nullptr;
}

void List::merge(const List & that)
{
	Node* curThis = first;
	Node* curThat = that.first;

	Node* curFirst = new Node();
	Node* cur = curFirst;
	while (!(curThis == nullptr && curThat == nullptr)) {
		if (curThis == nullptr) {
			cur->setNext(curThat);
			curThat->setPrev(cur);
			curThat = curThat->getNext();
		}
		else if (curThat == nullptr) {
			cur->setNext(curThis);
			curThis->setPrev(cur);
			curThis = curThis->getNext();
		}
		else if (*curThis->getValue() < *curThat->getValue()) {
			cur->setNext(curThis);
			curThis->setPrev(cur);
			curThis = curThis->getNext();
		}
		else {
			cur->setNext(curThat);
			curThat->setPrev(cur);
			curThat = curThat->getNext();
		}
		cur = cur->getNext();
	}
	
	first = curFirst->getNext();
	delete curFirst;
	first->setPrev(nullptr);
	last = cur;
	m_size += that.m_size;
}

void List::sort()
{
	if (m_size == 1)
	{
		return;
	}
	Node* mid = first;
	size_t newSize = m_size / 2;
	for (size_t i = 0; i < newSize; i++) {
		mid = mid->getNext();
	}

	List secondHalf;
	secondHalf.last = last;

	secondHalf.first = mid;
	last = mid->getPrev();
	
	secondHalf.first->setPrev(nullptr);
	last->setNext(nullptr);

	secondHalf.m_size = m_size - newSize;
	m_size = newSize;

	sort();
	secondHalf.sort();
	merge(secondHalf);
	secondHalf.first = nullptr;
	secondHalf.last = nullptr;
}

Node::Node()
{
}

Node::Node(const Circle * pc) : m_Data(*pc)
{
}

Node::Node(Node * prev, Node * next, const Circle * pc) : pPrev(prev), pNext(next), m_Data(*pc)
{	
}

Node::~Node()
{
	pPrev = nullptr;
	pNext = nullptr;
}

Circle * Node::getValue()
{
	return &m_Data;
}

ostream & operator<<(ostream & os, const List & l)
{
	Node* cur = l.first;
	os << "[ " << endl;
	while (cur != nullptr) {
		os << *cur->getValue() << "," << endl;
		cur = cur->getNext();
	};
	os << "]";
	return os;
}

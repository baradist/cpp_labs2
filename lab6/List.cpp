#include "List.h"

static bool compareBySquare(const Shape *s1, const Shape *s2) {
    return s1->square() < s2->square();
}

static bool compareByRemoteness(const Shape *s1, const Shape *s2) {
    return s1->remoteness() < s2->remoteness();
}

List::List() {
    first.pNext = &last;
    last.pPrev = &first;
    m_size = 0;
}

List::List(const List &copy) {
    first.pNext = &last;
    last.pPrev = &first;
    m_size = 0;
    Node *tmp = copy.first.pNext;
    while (tmp != &copy.last) {
        this->addLast(*tmp->m_Data);
        tmp = tmp->pNext;
    }
}

List::List(List &&copy) : m_size(copy.m_size) {
    first.pNext = copy.first.pNext;
    last.pPrev = copy.last.pPrev;
    first.pNext->pPrev = &first;
    last.pPrev->pNext = &last;
    copy.first.pNext = &copy.last;
    copy.last.pPrev = &copy.first;
    copy.m_size = 0;
}

List::~List() {
    while (first.pNext != &last) {
        delete first.pNext;
    }
}

List &List::operator=(List &that) {
    if (this == &that) {
        return *this;
    }
    Node *thisCur = first.pNext;
    Node *thatCur = that.first.pNext;
    for (size_t i = 1; i < m_size && i < that.m_size; i++) {
        copy(thisCur, thatCur);
        thisCur = thisCur->pNext;
        thatCur = thatCur->pNext;
    }
    copy(thisCur, thatCur);
    if (m_size > that.m_size) {
        clearAfter(thisCur->pNext);
        thisCur->pNext = &last;
        last.pPrev = thisCur;
    } else {
        thatCur = thatCur->pNext;
        while (thatCur != &that.last) {
            new Node(thisCur, thatCur->m_Data);
            thisCur = thisCur->pNext;
            thatCur = thatCur->pNext;
        }
    }
    m_size = that.m_size;
    return *this;
}

void List::copy(List::Node *copyTo, const List::Node *copyFrom) const {
    try {
        // reuse existing Shape, that matches
        *copyTo->m_Data = *copyFrom->m_Data;
    }
    catch (std::bad_cast &) {
        // otherwise, replace the Shape
        delete copyTo->m_Data;
        copyTo->m_Data = copyFrom->m_Data->clone();
    }
}

List &List::operator=(List &&that) {
    if (this == &that) {
        return *this;
    }
    first = that.first;
    first.pNext->pPrev = &first;
    last = that.last;
    last.pPrev->pNext = &last;

    that.first.pNext = &that.last;
    that.last.pPrev = &that.first;
    that.m_size = 0;

    return *this;
}

void List::addFirst(const Shape &shape) {
    new Node(&first, &shape);
    m_size++;
}

void List::addLast(const Shape &shape) {
    new Node(last.pPrev, &shape);
    m_size++;
}

void List::removeAll() {
    while (first.pNext != &last) {
        delete first.pNext;
    }
    m_size = 0;
}

bool List::remove(const Shape &shape) {
    Node *p = first.pNext;
    while (p != &last) {
        if (shape == *p->m_Data) {
            delete p;
            m_size--;
            return true;
        }
        p = p->pNext;
    }
    return false;
}

int List::removeAll(const Shape &shape) {
    int count = 0;
    Node *p = first.pNext;

    while (p != &last) {
        Node *pn = p->pNext;
        if (shape == *p->m_Data) {
            delete p;
            m_size--;
            count++;
        }
        p = pn;
    }
    return count;
}

List::Node::~Node() {
    if (pNext)
        pNext->pPrev = pPrev;
    if (pPrev)
        pPrev->pNext = pNext;
}

List::Node::Node() {
    pNext = nullptr;
    pPrev = nullptr;
}

List::Node::Node(Node *pp, const Shape *c) : m_Data(c->clone()) {
    Node *pn = pp->pNext;
    this->pPrev = pp;
    this->pNext = pn;
    pp->pNext = this;
    pn->pPrev = this;
}

void List::print(std::ostream &os) {
    Node *tmp = first.pNext;
    while (tmp != &last) {
        tmp->m_Data->print(os);
        tmp = tmp->pNext;
    }
    os << std::endl;
}

void List::sort(Sorting s) {
    if (s == SQUARE) {
        sort(compareBySquare);
    } else if (s == REMOTENESS) {
        sort(compareByRemoteness);
    }
}

void List::sort(bool (*compareBy)(const Shape *s1, const Shape *s2)) {
    if (m_size == 1) {
        return;
    }
    Node *mid = first.pNext;
    size_t newSize = m_size / 2;
    for (size_t i = 0; i < newSize; i++) {
        mid = mid->pNext;
    }

    List secondHalf;
    secondHalf.last.pPrev = last.pPrev;
    secondHalf.last.pPrev->pNext = &secondHalf.last;

    secondHalf.first.pNext = mid;
    last.pPrev = mid->pPrev;
    mid->pPrev = &secondHalf.first;

    last.pPrev->pNext = &last;

    secondHalf.m_size = m_size - newSize;
    m_size = newSize;

    sort(compareBy);
    secondHalf.sort(compareBy);
    merge(secondHalf, compareBy);
}

void List::merge(List &that, bool (*compareBy)(const Shape *s1, const Shape *s2)) {
    Node *curThis = first.pNext;
    Node *curThat = that.first.pNext;

    Node *cur = &first;
    while (!(curThis == &last && curThat == &that.last)) {
        if (curThis == &last) {
            cur->pNext = curThat;
            curThat->pPrev = cur;
            curThat = curThat->pNext;
        } else if (curThat == &that.last || compareBy(curThis->m_Data, curThat->m_Data)) {
            cur->pNext = curThis;
            curThis->pPrev = cur;
            curThis = curThis->pNext;
        } else {
            cur->pNext = curThat;
            curThat->pPrev = cur;
            curThat = curThat->pNext;
        }
        cur = cur->pNext;
    }

    last.pPrev = cur;
    last.pPrev->pNext = &last;
    m_size += that.m_size;

    that.first.pNext = &that.last;
    that.last.pPrev = &that.first;
    that.m_size = 0;
}

void List::clearAfter(Node *cur) {
    Node *next;
    while (cur->pNext != nullptr) { // while not a tail
        next = cur->pNext;
        delete cur;
        cur = next;
    }
}

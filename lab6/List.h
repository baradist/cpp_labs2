#pragma once

#include "Shape.h"
#include "Rect.h"
#include "Circle.h"

enum Sorting {
    SQUARE, REMOTENESS
};

static bool compareBySquare(const Shape *s1, const Shape *s2);

class List {
    class Node {
        friend class List;

        Node *pPrev;
        Node *pNext;
        Shape *m_Data;

        Node();

        Node(Node *p, const Shape *c);

        ~Node();
    };

    Node first;
    Node last;
    unsigned int m_size;

    void sort(bool (*compareBy)(const Shape *s1, const Shape *s2));

    void merge(List &that, bool (*compareBy)(const Shape *s1, const Shape *s2));

    void clearAfter(Node *cur);

public:
    List();

    List(const List &copy);

    List(List &&copy);

    ~List();

    List &operator=(List &other);

    List &operator=(List &&that);

    virtual void addFirst(const Shape &shape);

    void addLast(const Shape &shape);

    bool remove(const Shape &shape);

    int removeAll(const Shape &shape);

    void removeAll();

    void print(std::ostream &os);

    void sort(Sorting);

    void copy(Node *copyTo, const Node *copyFrom) const;
};

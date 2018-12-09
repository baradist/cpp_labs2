#pragma once

#include <iostream>
#include "WrongIndexException.h"

template<class T>
class MyLinkedStack {
    class Node {
        friend class MyLinkedStack;

        Node *next;
        const T *data;

        Node() : next(nullptr), data(nullptr) {};

        Node(const T &t, Node *p) : next(p), data(new T(t)) {}; // for pushing

        Node(Node *p, const T &t) : data(new T(t)) { // for copying the whole stack
            p->next = this;
        };

        ~Node() {
            next = nullptr;
            delete data; // TODO: ???
            data = nullptr;
        };
    };

    Node head;
    size_t size;

    void copy(Node *copyTo, const Node *copyFrom) const {
        *copyTo->data = *copyFrom->data;
    }

    void clearAfter(Node *cur) {
        Node *next;
        while (cur) { // while not a tail
            next = cur->next;
            delete cur;
            --size;
            cur = next;
        }
    }

    static void print(std::ostream &os, const Node *start) {
        const Node *cur = start;
        while (cur) {
            os << *cur->data << std::endl;
            cur = cur->next;
        }
        os << std::endl;
    }

    Node *getReverced(Node *start) {
        Node *cur = start;
        Node *result = nullptr;
        while (cur) {
            result = new Node(*cur->data, result);
            cur = cur->next;
        }
        return result;
    }

public:
    MyLinkedStack() : size(0) {}

    MyLinkedStack(const MyLinkedStack &that) {
        Node *curThat = &that.head;
        Node *curThis = &head;

        while (curThat) {
            curThis = new Node(curThis, curThat->data);
            curThat = curThat->next;
        }
        size = that.size;
    }

    MyLinkedStack(MyLinkedStack &&that) {
        head.next = that.head.next;
        that.head.next = nullptr;
        size = that.size;
        that.size = 0;
    }

    ~MyLinkedStack() {
        clearAfter(head.next);
    }

    MyLinkedStack &operator=(const MyLinkedStack &that) {
        if (this == &that) {
            return *this;
        }
        Node *thisCur = head.next;
        Node *thatCur = that.head.next;
        for (size_t i = 1; i < size && i < that.size; i++) {
            copy(thisCur, thatCur);
            thisCur = thisCur->next;
            thatCur = thatCur->next;
        }
        copy(thisCur, thatCur);
        if (size > that.size) {
            clearAfter(thisCur->next);
            thisCur->next = nullptr;
        } else {
            thatCur = thatCur->next;
            while (thatCur) {
                thisCur = new Node(thisCur, thatCur->data);
                thatCur = thatCur->next;
            }
        }
        size = that.size;
        return *this;
    }

    MyLinkedStack &operator=(MyLinkedStack &&that) {
        return *this;
    }

    bool operator==(const MyLinkedStack &other) const {
        return false;
    }

    T pop() { // TODO: T, const T or T*
        if (size == 0) {
            throw /*WrongIndexException*/("Stack is empty");
        }
        T result = *head.next->data;
        Node *toDelete = head.next;
        head.next = head.next->next;
        delete toDelete;
        --size;
        return result;
    }

    void push(const T &t) {
        head.next = new Node(t, head.next);
        ++size;
    }

    void print(std::ostream &os) {
        Node *node = getReverced(head.next);
        print(os, node);
        clearAfter(node);
    }

    void printBackward(std::ostream &os) const {
        print(os, head.next);
    }
};

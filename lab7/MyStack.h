#pragma once

#include <iostream>

template<class T, int capacity>
class MyStack {
    T arr[capacity];
    size_t size;

public:
    MyStack() : size(0) {}

    T &operator[](int i) {
        if (i < 0 || i >= size) {
            throw "Incorrect index";
        }
        return arr[i];
    }

    T &pop() {
        if (size == 0) {
            throw "Stack is empty";
        }
        return arr[--size];
    }

    void push(T t) {
        if (size == capacity) {
            throw "Stack is full";
        }
        arr[size++] = t;
    }
};

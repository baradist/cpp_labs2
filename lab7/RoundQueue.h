
#ifndef LAB7_ROUNDQUEUE_H
#define LAB7_ROUNDQUEUE_H

#include <cstddef>
#include <cstdlib>

template<class T>
class RoundQueue {
    size_t cap;
    size_t size;
    size_t first;
    size_t last;
    T *buf;

protected:
    inline size_t getAndIncrement(size_t &index) {
        size_t result = index;
        index = (index + 1) % cap;
        return result;
    }

    void reallocateBuffer() {
        size_t newCap = cap * 3 / 2 + 1;
        T *newBuf = new T[newCap];
        for (size_t i = 0, j = first; i < size; ++i) {
            newBuf[i] = buf[getAndIncrement(j)];
        }
        clearBuffer();
        buf = newBuf;
        cap = newCap;
        first = 0;
        last = size;
    }

    void clearBuffer() const {
        for (int i = 0; i < cap; ++i) {
            buf[i].~T();
        }
        delete[] buf;
    }

public:
    RoundQueue() : cap(10), size(0), first(0), last(0), buf(new T[10]) {
        for (int i = 0; i < cap; ++i) {
            buf[i] = T();
        }
    }

    RoundQueue(size_t capacity) : cap(capacity), size(0), first(0), last(0), buf(new T[capacity]) {
        for (int i = 0; i < cap; ++i) {
            buf[i] = T();
        }
    }

    RoundQueue(size_t capacity, const T &t) : cap(capacity), size(0), first(0), last(capacity) {
        buf = static_cast<T *>(malloc(sizeof(T) * cap));
        for (int i = 0; i < cap; ++i) {
            new(&buf[i])T(t);
        }
    }

    RoundQueue(const RoundQueue &v) : cap(v.size), size(v.size), first(0), last(v.size) {
        buf = static_cast<T *>(malloc(sizeof(T) * cap));
        for (int i = 0; i < cap; ++i) {
            new(&buf[i])T(v.buf[i]);
        }
    }

    virtual ~RoundQueue() {
        clearBuffer();
    }

    void add(const T &t) {
        if (size == cap) {
            reallocateBuffer();
        }
        buf[getAndIncrement(last)] = t;
        ++size;
    }

    T &remove() {
        if (!size) {
            throw "Queue is empty";
        }
        --size;
        return buf[getAndIncrement(first)];
    }

    T &element() {
        return buf[first];
    }
};

#endif //LAB7_ROUNDQUEUE_H

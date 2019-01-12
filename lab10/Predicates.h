#ifndef LAB10_PREDICATES_H
#define LAB10_PREDICATES_H

#include "Point.h"

template<typename T>
struct Print {
    static void print(const T &t) {
        std::cout << t << std::endl;
    }
};

//template <typename T>
class ChangeCords {
    int x;
public:
    ChangeCords(int value) : x(value) {};

    void operator()(Point &p) {
        p.setX(p.getX() + x);
        p.setY(p.getY() + x);
    };
};

#endif //LAB10_PREDICATES_H

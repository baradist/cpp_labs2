#pragma once

#include <iostream>

class Circle;

class Point {
    int m_x, m_y;

public:
    Point(int x = 0, int y = 0);

    Point(const Point &that);

    Point(Point &&that);

    ~Point();

    Point &operator=(const Point &that);

    bool operator==(const Point &that) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    inline int getX() const { return m_x; };

    inline int getY() const { return m_y; };
};

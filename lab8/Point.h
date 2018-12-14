#pragma once

#include <iostream>

class Circle;

class Point {
    int m_x, m_y;

public:
    static bool anyCoordIsNegative(const Point &p);

    explicit Point(int x = 0, int y = 0);

    Point(const Point &that) = default;

    Point(Point &&that) noexcept = default;

    ~Point() = default;

    Point &operator=(const Point &that) = default;

    bool operator==(const Point &that) const;

    bool operator<(const Point &that) const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    inline int getX() const { return m_x; };

    inline int getY() const { return m_y; };
};

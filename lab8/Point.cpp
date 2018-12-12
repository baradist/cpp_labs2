#include "Point.h"

Point::Point(int x, int y) {
    m_x = x;
    m_y = y;
}

Point::Point(const Point &that) {
    m_x = that.m_x;
    m_y = that.m_y;
}

Point::Point(Point &&that) {
    m_x = that.m_x;
    m_y = that.m_y;
    that.m_x = 0;
    that.m_y = 0;
}

Point::~Point() {
}

Point &Point::operator=(const Point &that) {
    if (this != &that) {
        m_x = that.m_x;
        m_y = that.m_y;
    }
    return *this;
}

bool Point::operator==(const Point &that) const {
    if (m_x == that.m_x && m_y == that.m_y)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "Point: { m_x = " << p.m_x << ", m_y = " << p.m_x << " } ";
    return os;
}

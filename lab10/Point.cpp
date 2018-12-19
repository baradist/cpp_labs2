#include "Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y) {
}

bool Point::operator==(const Point &that) const {
    return m_x == that.m_x && m_y == that.m_y;
}

bool Point::operator<(const Point &that) const {
    return (m_x * m_x + m_y * m_y) < (that.m_x * that.m_x + that.m_y * that.m_y);
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
    os << "Point: { m_x = " << p.m_x << ", m_y = " << p.m_y << " } ";
    return os;
}

bool Point::anyCoordIsNegative(const Point &p) {
    return p.m_x < 0 || p.m_y < 0;
}

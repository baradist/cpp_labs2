#include "Rect.h"
#include <cmath>

Rect::Rect() {
    m_left = 0;
    m_right = 0;
    m_top = 0;
    m_bottom = 0;
}

Rect::Rect(Color color, int left, int right, int top, int bottom) : Shape(color) {
    m_left = left;
    m_top = top;
    m_right = right;
    m_bottom = bottom;
    normalize();
}

Rect::Rect(const Rect &that) : Shape(that) {
    m_left = that.m_left;
    m_right = that.m_right;
    m_top = that.m_top;
    m_bottom = that.m_bottom;
}

Rect::~Rect() {
    std::cout << "Now I am in Rect's destructor!" << std::endl;
}

void Rect::WhereAmI() {
    std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::normalize() {
    if (m_left > m_right) {
        m_left ^= m_right;
        m_right ^= m_left;
        m_left ^= m_right;
    }
    if (m_top > m_bottom) {
        m_top ^= m_bottom;
        m_bottom ^= m_top;
        m_top ^= m_bottom;
    }
}

void Rect::inflate(int value) {
    m_left -= value;
    m_right += value;
    m_top -= value;
    m_bottom += value;
    normalize();
}

float Rect::square() const {
    return (m_right - m_left) * (m_bottom - m_top);
}

float Rect::remoteness() const {
    return sqrt(m_left * m_left + m_top * m_top);
}

Rect *Rect::clone() const {
    return new Rect(*this);
}

bool Rect::operator==(const Shape &s) const {
    if (!Shape::operator==(s)) {
        return false;
    }
    if (const Rect *pr = dynamic_cast<const Rect *>(&s)) {
        if (m_left == pr->m_left && m_right == pr->m_right && m_bottom == pr->m_bottom && m_top == pr->m_top) {
            return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Rect &r) {
    return os << "Rect: { color = " << r.m_color << ", m_left = " << r.m_left << ", m_right = " << r.m_right
              << ", m_top = " << r.m_top << ", m_bottom = " << r.m_bottom << " }"
              << " Square = " << r.square() << ", remoteness = " << r.remoteness();
}

void Rect::print(std::ostream &os) {
    os << *this << std::endl;
}

Rect &Rect::operator=(const Shape &that) {
    Shape::operator=(that);
    const Rect &pr = dynamic_cast<const Rect &>(that);
    return *this = pr;
}

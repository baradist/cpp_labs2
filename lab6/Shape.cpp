#include "Shape.h"

Shape::Shape(Color color) : m_color(color) {
}

bool Shape::operator==(const Shape &s) const {
    return m_color == s.m_color;
}

Shape &Shape::operator=(const Shape &that) {
    m_color = that.m_color;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Shape &c) {
    return os << "Shape { color=" << c.m_color << " }";
}

void Shape::print(std::ostream &os) {
    os << *this << std::endl;
}

Shape::Shape(const Shape &that) {
    m_color = that.m_color;
}

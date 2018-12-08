#include "Circle.h"
#include <cmath>


Circle::Circle(Color color, int x, int y, double radius) : Shape(color), radius(radius), center(x, y) {
}

Circle::Circle(const Circle &that) : radius(that.radius), center(that.center) {
}

Circle::~Circle() {
}

Circle &Circle::operator=(const Shape &that) {
    Shape::operator=(that);
    const Circle &pr = dynamic_cast<const Circle &>(that);
    return *this = pr;
}

float Circle::square() const {
    return 3.14 * radius * radius;
}

float Circle::remoteness() const {
    int x = center.getX();
    int y = center.getY();
    return sqrt(x * x + y * y);
}

Circle *Circle::clone() const {
    return new Circle(*this);
}

std::ostream &operator<<(std::ostream &os, const Circle &c) {
    return os << "Circle: { color = " << c.m_color << ", center = " << c.center << ", radius = " << c.radius << " }"
              << " Square = " << c.square() << ", remoteness = " << c.remoteness();
}

bool Circle::operator==(const Shape &s) const {
    if (!Shape::operator==(s)) {
        return false;
    }
    if (const Circle *pc = dynamic_cast<const Circle *>(&s)) {
        if (center == pc->center && radius == pc->radius) {
            return true;
        }
    }
    return false;
}

void Circle::print(std::ostream &os) {
    os << *this << std::endl;
}

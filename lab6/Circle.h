#pragma once

#include "Point.h"
#include "Shape.h"
#include <iostream>

class Circle : public Shape {
    Point center;
    double radius;

public:
    Circle(Color color = RED, int x = 0, int y = 0, double Radius = 0);

    Circle(const Circle &that);

    virtual ~Circle();

    virtual Circle &operator=(const Shape &that);

    virtual bool operator==(const Shape &s) const;

    friend std::ostream &operator<<(std::ostream &os, const Circle &c);

    virtual float square() const;

    virtual float remoteness() const;

    virtual Circle *clone() const;

    virtual void print(std::ostream &os);
};

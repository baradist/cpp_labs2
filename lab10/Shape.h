#pragma once

#include <iostream>

enum Color {
    RED, GREEN, BLUE
};

class Shape {

protected:
    Color m_color;

public:

    Shape(const Shape &that);

    explicit Shape(Color color = RED);

    virtual ~Shape() = default;

    virtual bool operator==(const Shape &s) const;

    virtual Shape &operator=(const Shape &that) = default;

    friend std::ostream &operator<<(std::ostream &os, const Shape &c);

    virtual double square() const = 0;

    virtual double remoteness() const = 0;

    virtual Shape *clone() const = 0;

    virtual void print(std::ostream &os);
};

#pragma once

#include "Shape.h"

class Rect : public Shape {
    int m_left, m_right, m_top, m_bottom;

public:
    Rect();

    Rect(Color color = RED, int left = 0, int top = 0, int right = 0, int bottom = 0);

    Rect(const Rect &that);

    virtual ~Rect();

    friend std::ostream &operator<<(std::ostream &os, const Rect &r);

    virtual bool operator==(const Shape &r) const;

    virtual Rect &operator=(const Shape &that);

    virtual void WhereAmI();

    void normalize();

    virtual void inflate(int value);

    virtual float square() const;

    virtual float remoteness() const;

    virtual Rect *clone() const;

    virtual void print(std::ostream &os);
};

#pragma once

#include "Shape.h"

class Rect : public Shape {
    int m_left, m_right, m_top, m_bottom;

public:
    //Rect() = default;

    explicit Rect(Color color = RED, int left = 0, int top = 0, int right = 0, int bottom = 0) : Shape(color) {
		m_left = left;
		m_top = top;
		m_right = right;
		m_bottom = bottom;
		normalize();
	};

    Rect(const Rect &that) = default;

    virtual ~Rect() = default;

    friend std::ostream &operator<<(std::ostream &os, const Rect &r);

    virtual bool operator==(const Shape &r) const;

    Rect &operator=(const Shape &that) throw();

    void normalize();

    virtual void inflate(int value);

    virtual double square() const;

    virtual double remoteness() const;

    virtual Rect *clone() const;

    virtual void print(std::ostream &os);
};

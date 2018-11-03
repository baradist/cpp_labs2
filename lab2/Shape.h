#ifndef LAB1_SHAPE_H
#define LAB1_SHAPE_H

#include "Color.h"

class Shape {
protected:
    Color color;

public:
	Shape() = default;
	Shape(const Shape &that) = default;
	Shape(Color color);
	virtual ~Shape();
	virtual double GetSquare() const = 0;
	virtual Color GetColor();
    virtual void WhereAmI();
	virtual void Inflate(double i) = 0;
};

#endif //LAB1_SHAPE_H

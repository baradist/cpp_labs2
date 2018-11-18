#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "Shape.h"
#include "Rect.h"

class Circle : public Shape {
	double x;
	double y;
	double radius;

public:
    Circle(const Rect &that);
    Circle(const Circle &that);
    Circle(double x = 0, double y = 0, double radius = 0, Color color = WHITE);
	virtual ~Circle();
    double GetSquare() const;
    virtual void WhereAmI() const;
    virtual void Inflate(double i);
};

#endif //LAB1_CIRCLE_H

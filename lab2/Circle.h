#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(const Shape &that);

    Circle(const Circle &that);

    Circle(double x = 0, double y = 0, double radius = 0, Color color = WHITE);

    virtual ~Circle();

    double GetSquare() const;

    virtual void WhereAmI();

    virtual void Inflate(double i);
};

#endif //LAB1_CIRCLE_H

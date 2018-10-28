#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double x = 0, double y = 0, double radius = 0, Color color = WHITE);

    ~Circle();

    double GetSquare() const;

    virtual void WhereAmI();
};

#endif //LAB1_CIRCLE_H

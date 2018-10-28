#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double x = 0, double y = 0, double radius = 0, Color color = WHITE);

    double GetSquare() const;
};

#endif //LAB1_CIRCLE_H

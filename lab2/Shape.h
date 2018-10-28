#ifndef LAB1_SHAPE_H
#define LAB1_SHAPE_H

#include "Color.h"

class Shape {
protected:
    double x;
    double y;
    double size;
    Color color;

public:
    Shape(double x = 0, double y = 0, double size = 0, Color color = WHITE);

    ~Shape();

    double GetSquare() const;

    Color GetColor() {
        return color;
    }
};

#endif //LAB1_SHAPE_H

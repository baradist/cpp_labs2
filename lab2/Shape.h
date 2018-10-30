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
    Shape(const Shape &that);

    Shape(double x = 0, double y = 0, double size = 0, Color color = WHITE);

    virtual ~Shape();

    double GetSquare() const;

    Color GetColor() {
        return color;
    }

    virtual void WhereAmI();

    void Inflate(double i) = 0;
};

#endif //LAB1_SHAPE_H

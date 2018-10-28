#ifndef LAB1_RECT_H
#define LAB1_RECT_H

#include "Shape.h"

class Rect : public Shape {
protected:
    double sizeY;

public:
    Rect(double x = 0, double y = 0, double width = 0, double height = 0, Color color = WHITE);

    ~Rect();

    double GetSquare() const;
};

#endif //LAB1_RECT_H

#include "Rect.h"

Rect::Rect(double x, double y, double width, double height, Color color) : Shape(x, y, width, color) {
    this->sizeY = height;
}

double Rect::GetSquare() const {
    return size * sizeY;
}

#include "Circle.h"

Circle::Circle(double x, double y, double radius, Color color) : Shape(x, y, radius, color) {

}

double Circle::GetSquare() const {
    return 3.14 * size * size;
}
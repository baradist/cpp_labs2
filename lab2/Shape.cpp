#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(const Shape &that) {
    Shape(that.x, that.y, that.size, that.color);
}

Shape::Shape(double x, double y, double size, Color color) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->color = color;
}

Shape::~Shape() {
    cout << "Now I am in Shape's destructor!" << endl;
}

void Shape::WhereAmI() {
    cout << "Now I am in a class Shape" << endl;
}

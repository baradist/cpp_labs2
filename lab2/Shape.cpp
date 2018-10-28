#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(double x, double y, double size, Color color) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->color = color;
}

Shape::~Shape() {

}

void Shape::WhereAmI() {
    cout << "Now I am in a class Shape" << endl;
}

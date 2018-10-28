#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(const Shape &that) : Shape(that) {

}

Circle::Circle(const Circle &that) {
    Circle(that.x, that.y, that.size, that.color);
}

Circle::Circle(double x, double y, double radius, Color color) : Shape(x, y, radius, color) {

}

Circle::~Circle() {
    cout << "Now I am in Circle's destructor!" << endl;
}

double Circle::GetSquare() const {
    return 3.14 * size * size;
}

void Circle::WhereAmI() {
    cout << "Now I am in a class Circle" << endl;
}

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double x, double y, double radius, Color color) : Shape(x, y, radius, color) {

}

Circle::~Circle() {

}

double Circle::GetSquare() const {
    return 3.14 * size * size;
}

void Circle::WhereAmI() {
    cout << "Now I am in a class Circle" << endl;
}

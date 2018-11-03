#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(const Shape &that) : Shape(that) {
	x = 0;
	y = 0;
	radius = 0;
}

Circle::Circle(const Circle &that) : Shape(that) {
	x = that.x;
	y = that.y;
	radius = that.radius;
}

Circle::Circle(double x, double y, double radius, Color color) : Shape(color) {
	this->x = x;
	this->y = y;
	this->radius = radius;
}

Circle::~Circle() {
    cout << "Now I am in Circle's destructor!" << endl;
}

double Circle::GetSquare() const {
    return 3.14 * radius * radius;
}

void Circle::WhereAmI() {
    cout << "Now I am in a class Circle" << endl;
}

void Circle::Inflate(double i) {
	radius += i;
}

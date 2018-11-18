#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(const Rect &that) : Shape(that) {
	x = that.x - (that.width / 2);
	y = that.y - (that.heigth / 2);
	radius = sqrt((that.width / 2) * (that.width / 2) + (that.heigth / 2) * (that.heigth / 2));
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

void Circle::WhereAmI() const {
    cout << "Now I am in a class Circle" << endl;
}

void Circle::Inflate(double i) {
	radius += i;
}

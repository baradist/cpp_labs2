#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(const Rect &that) : Shape(color) {
	x = that.x;
	y = that.y;
	width = that.width;
	heigth = that.heigth;
}

Rect::Rect(double x, double y, double width, double height, Color color) : Shape(color) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->heigth = height;
}

Rect::~Rect() {
    cout << "Now I am in Rect's destructor!" << endl;
}

double Rect::GetSquare() const {
    return width * heigth;
}

void Rect::WhereAmI() {
    cout << "Now I am in a class Rect" << endl;
}

void Rect::Inflate(double i) {
	width += i;
	heigth += i;
}

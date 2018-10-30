#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(const Rect &that) {
    Rect(that.x, that.y, that.size, that.sizeY, that.color);
}

Rect::Rect(double x, double y, double width, double height, Color color) : Shape(x, y, width, color) {
    this->sizeY = height;
}

Rect::~Rect() {
    cout << "Now I am in Rect's destructor!" << endl;
}

double Rect::GetSquare() const {
    return size * sizeY;
}

void Rect::WhereAmI() {
    cout << "Now I am in a class Rect" << endl;
}

void Rect::Inflate(double i) {
    size += i;
    sizeY += i;
}

#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(double x, double y, double width, double height, Color color) : Shape(x, y, width, color) {
    this->sizeY = height;
}

Rect::~Rect() {

}

double Rect::GetSquare() const {
    return size * sizeY;
}

void Rect::WhereAmI() {
    cout << "Now I am in a class Rect" << endl;
}

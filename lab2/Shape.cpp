#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	color = WHITE;
}

Shape::Shape(Color color) {
    color = color;
}

Shape::~Shape() {
    cout << "Now I am in Shape's destructor!" << endl;
}

Color Shape::GetColor() const
{
	return color;
}

void Shape::WhereAmI() {
    cout << "Now I am in a class Shape" << endl;
}

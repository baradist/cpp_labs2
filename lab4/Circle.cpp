#include "Circle.h"


Circle::Circle()
{
	radius = 0;
}

Circle::Circle(const Point & point, double radius)
{
	this->point = point;
	this->radius = radius;
}

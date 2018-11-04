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

bool operator==(const Circle & c1, const Circle & c2)
{
	return &c1 == &c2 || (c1.point == c2.point && c1.radius == c2.radius);
}

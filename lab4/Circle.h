#pragma once

#include "Point.h"
class Circle
{
	Point point;
	double radius;

public:
	Circle();
	Circle(const Point& point, double radius);
	~Circle() = default;
};


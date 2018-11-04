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

	friend bool operator==(const Circle & c1, const Circle & c2);
};

bool operator==(const Circle& c1, const Circle& c2);

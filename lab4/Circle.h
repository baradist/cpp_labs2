#pragma once

#include "Point.h"
#include <iostream>

using namespace std;

class Circle
{
	Point point;
	double radius;

public:
	Circle();
	Circle(const Point& point, double radius);
	~Circle() = default;

	friend bool operator==(const Circle & c1, const Circle & c2);

	friend ostream& operator<<(ostream& os, const Circle& c);
};

bool operator==(const Circle& c1, const Circle& c2);

ostream& operator<<(ostream& os, const Circle& c);

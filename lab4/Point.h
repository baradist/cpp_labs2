#pragma once

#include <iostream>

using namespace std;

class Point
{
	double x;
	double y;

public:
	Point();
	Point(double x, double y);

	friend bool operator==(const Point & p1, const Point & p2);

	friend ostream& operator<<(ostream& os, const Point& p);
};

bool operator==(const Point& p1, const Point& p2);

ostream& operator<<(ostream& os, const Point& p);

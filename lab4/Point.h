#pragma once
class Point
{
	double x;
	double y;

public:
	Point();
	Point(double x, double y);

	friend bool operator==(const Point & p1, const Point & p2);
};

bool operator==(const Point& p1, const Point& p2);

#include "Point.h"


Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

bool operator==(const Point & p1, const Point & p2)
{
	return &p1 == &p2 || (p1.x == p2.x && p1.y == p2.y);
}

ostream& operator<<(ostream& os, const Point& p)
{
	return os << "Point: { x=" << p.x << ", y=" << p.y << " }";
}
#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


Point::~Point()
{
}

Point & Point::operator+=(const Point & that)
{
	this->x += that.x;
	this->y += that.y;
	return *this;
}

Point & Point::operator+=(const int i)
{
	this->x += i;
	this->y += i;
	return *this;
}

Point Point::operator-(const int i)
{
	return Point(this->x - i, this->y - i);
}

Point Point::operator-(const Point & that)
{
	return Point(this->x - that.x, this->y - that.y);
}

Point Point::operator+()
{
	return *this;
}

Point Point::operator-()
{
	this->x = -this->x;
	this->y = -this->y;
	return *this;
}

Point operator+(const Point & p1, const Point & p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator+(int i, const Point & p2)
{
	return Point(i + p2.x, i + p2.y);
}

Point operator+(const Point & p1, int i)
{
	return Point(i + p1.x, i + p1.y);
}

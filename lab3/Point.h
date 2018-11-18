#pragma once
class Point
{
	int x;
	int y;

	friend Point operator+(const Point & p1, const Point & p2);

	friend Point operator+(int i, const Point & p2);

	friend Point operator+(const Point & p1, int i);

public:
	Point();

	Point(int x, int y);

	virtual ~Point();

	Point & operator+=(const Point & that);

	Point & operator+=(const int i);

	Point operator-(const int i) const;

	Point operator-(const Point& that) const;

	const Point& operator+() const;

	Point operator-();
};

Point operator+(const Point & p1, const Point & p2);

Point operator+(int i, const Point & p2);

Point operator+(const Point & p1, int i);

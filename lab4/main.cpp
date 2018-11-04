#include <iostream>
#include "Circle.h"
#include "LIst.h"

using namespace std;

int main() {
	const Point p(4, 5);
	Circle c(p, 42.);
	Circle c1(p, 43.);
	List l;
	l.addFirst(c);
	l.addFirst(c1);
	//l.remove(c); // TODO: leaks?
	for (size_t i = 0; i < 2; i++)
	{
		cout << l.get(i) << endl;
	}
	cout << "";
}
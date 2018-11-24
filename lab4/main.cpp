#include <iostream>
#include <fstream>
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
	cout << endl;
	for (size_t i = 0; i < 2; i++)
	{
		cout << l[i] << endl;
	}
	cout << endl;
	cout << l << endl;

	ofstream file("data.txt");
	file << l << endl;

	cout << "" << endl;

	l.addLast(Circle(p, 44));
	l.addLast(Circle(p, 35));
	l.addLast(Circle(p, 30));
	l.addLast(Circle(p, 25));
	l.addLast(Circle(p, 20));
	l.addLast(Circle(p, 15));
	l.addLast(Circle(p, -1));
	cout << "Before sorting" << endl << l << endl;

    l.sort();
    cout << "Before sorting" << endl << l << endl;

	List l2;
	l2.addLast(Circle(p, 50));
	l2.addLast(Circle(p, 51));
	l = l2;
	cout << l2 << endl;

	List l3(l);
	cout << l3 << endl;

	l.clear();
	l.clear();
	cout << l << endl;
	cout << "";
}
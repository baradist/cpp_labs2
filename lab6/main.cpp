#include <iostream>
#include "Circle.h"
#include "List.h"

int main() {
    Circle circle(RED, 2, 3, 6);
    Rect rect(RED, 1, 2, 3, 4);
    Rect rect_1(BLUE, 0, 2, 0, 2);

    List list;
    list.addFirst(circle);
    list.addLast(rect);
    list.addLast(rect_1);
    list.print(std::cout);
    list.remove(rect);

    list.print(std::cout);
    list.removeAll();

    list.print(std::cout);
    list.addFirst(circle);
    list.addLast(rect);
    list.addLast(rect);
    list.addLast(rect_1);
    list.print(std::cout);
    List list1 = list;

    list1.print(std::cout);
    list1.addLast(rect);
    list.addFirst(Circle(RED, 7, 6, 1));

    list1.print(std::cout);
    list.print(std::cout);
    list1 = list;
    list.print(std::cout);

    list1.removeAll(rect);
    list1.print(std::cout);

    std::cout << circle.square() << std::endl;
    std::cout << rect.square() << std::endl;
    std::cout << rect_1.square() << std::endl;

    list.addLast(Circle(RED, 5, 6, 2));
    list.addLast(Circle(RED, 7, 6, 1));
    list.addLast(Circle(RED, -7, 6, 3));
    list.sort(SQUARE);
    list.print(std::cout);
    list.sort(REMOTENESS);
    list.print(std::cout);

    std::cout << "stop";
}

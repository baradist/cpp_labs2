// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Point.h"
#include "Functions.h"

using namespace std;

int main() {

///////////////////////////////////////////////////////////////////

    //Задание 1. Итераторы

    //Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
    //нужно перегрузить в классе Point. Создайте вектор, элементы которого
    //являются копиями элементов set, но упорядочены по убыванию
    {
        set<Point> set_points = {Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4),};
        print_container(set_points);
        vector<Point> vector_points_reversed(set_points.rbegin(), set_points.rend());
        print_container(vector_points_reversed);

        //Потоковые итераторы. С помощью ostream_iterator выведите содержимое
        //vector и set из предыдущего задания на экран.
        copy(set_points.begin(), set_points.end(), ostream_iterator<Point>(cout, "\n"));
        copy(vector_points_reversed.begin(), vector_points_reversed.end(), ostream_iterator<Point>(cout, "\n"));

        //Итераторы вставки. С помощью возвращаемых функциями:
        //back_inserter()
        //front_inserter()
        //inserter()
        //итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
        //какие из итераторов вставки можно использовать с каждым контейнером.
        vector<int> vector_int = {11, 12, 13};
        set<int> set_int = {1, 2, 3, 4, 5};
        copy(set_int.begin(), set_int.end(), back_inserter(vector_int));
        // error: ‘class std::vector<int>’ has no member named ‘push_front’
//    copy(--set_int.end(), set_int.end(), front_inserter(vector_int));
        copy(set_int.begin(), ++set_int.begin(), inserter(vector_int, ++vector_int.begin()));
        print_container(vector_int);

///////////////////////////////////////////////////////////////////

        //Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

        // алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
        //(массив, vector, list...)
        //С помощью алгоритма for_each в любой последовательности с элементами любого типа
        //распечатайте значения элементов
        //Подсказка : неплохо вызываемую функцию определить как шаблон
        for_each(vector_int.begin(), vector_int.end(), Print<int>::print);

        cout << endl;

        //С помощью алгоритма for_each в любой последовательности с элементами типа Point
        //измените "координаты" на указанное значение (такой предикат тоже стоит реализовать
        //как шаблон) и выведите результат с помощью предыдущего предиката
        auto lambda_change_point_coords = [](Point &p) {
            p.setX(p.getX() + 10);
            p.setY(p.getY() + 10);
        };
        for_each(vector_points_reversed.begin(), vector_points_reversed.end(), lambda_change_point_coords);
        for_each(vector_points_reversed.begin(), vector_points_reversed.end(), Print<Point>::print);
    }
    //С помощью алгоритма find() найдите в любой последовательности элементов Point
    //все итераторы на элемент Point с указанным значением.
    {
        vector<Point> vector_points = {
                Point(1, 1),
                Point(2, 2),
                Point(3, 3),
                Point(4, 4),
                Point(2, 2),
                Point(3, 3),
                Point(4, 4),
                Point(3, 3),
                Point(4, 4),
                Point(4, 4),
        };
        multiset<Point> multiset_points(vector_points.begin(), vector_points.end());
        cout << "find()" << endl;
        Point findValue = Point(4, 4);
        for (multiset<Point>::iterator i = multiset_points.begin(),
                     end = multiset_points.end(); i != end; ++i) {
            i = find(i, end, findValue);
            if (i != end) {
                cout << *i << endl;
            }
        }

        //С помощью алгоритма sort() отсортируйте любую последовательность элементов Point.
        ////По умолчанию алгоритм сортирует последовательность по возрастанию.
        //Что должно быть определено в классе Point?
        // Замечание: обобщенный алгоритм sort не работает со списком, так как
        //это было бы не эффективно => для списка сортировка реализована методом класса!!!
        sort(vector_points.begin(), vector_points.end());
        print_container(vector_points);

        sort(vector_points.begin(), vector_points.end(), [](const Point &l, const Point &r) {
            return l.getY() > r.getY();
        });
        print_container(vector_points);

        //С помощью алгоритма find_if() найдите в любой последовательности элементов Point
        //итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
        //[-n, +m].
        const int n = 2, m = 3;
        multiset<Point>::iterator it = find_if(multiset_points.begin(), multiset_points.end(),
                                               [](const Point &p) {
                                                   return p.getX() >= -n && p.getX() <= m
                                                          && p.getY() >= -n && p.getY() <= m;
                                               }
        );
        cout << *it << endl;

        //С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
        //располагая прямоугольники по удалению центра от начала координат.





    }

    {//transform
        //Напишите функцию, которая с помощью алгоритма transform переводит
        //содержимое объекта string в нижний регистр.
        //Подсказка: класс string - это "почти" контейнер, поэтому для него
        // определены методы begin() и end()


        //Заполните list объектами string. С помощью алгоритма transform сформируте
        //значения "пустого" set, конвертируя строки в нижний регистр




        cout << endl;
    }
    {// map

        //Сформируйте любым способом вектор с элементами типа string.
        //Создайте (и распечатайте для проверки) map<string, int>, который будет
        //содержать упорядоченные по алфавиту строки и
        //количество повторений каждой строки в векторе








    };


    return 0;
}


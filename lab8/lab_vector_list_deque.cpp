//Стандартная библиотека шаблонов - STL 
//Контейнеры стандартной библиотеки - vector
//Итераторы

#include <iostream>
#include <vector>
#include <cstring>
#include "myString.h"
#include "Point.h"


void insertFirstIfDoesntContain(std::vector<char> &v, char c);

template<typename T>
void removeDuplicates(std::vector<T> &v);

#pragma warning(disable: 4786)


using namespace std;

template<typename T>
void printVectorParameters(std::ostream &os, vector<T> vector) {
    os << "size(): " << vector.size()
       << ", capacity(): " << vector.capacity()
       << ", max_size(): " << vector.max_size() << std::endl;
    for (int i = 0; i < vector.size(); ++i) {
        os << "vector[" << i << "]: " << vector[i] << std::endl;
    }
    os << std::endl;
}

int main() {
    // Контейнер стандартной библиотеки vector

//////////////////////////////////////////////////////////////////////
    //Создание векторов.

    //Создайте следующие вектора:
    //---------------------------
    //пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
    //что его размер нулевой.
    {
        vector<int> vInt;
        size_t sizeV = vInt.size();


        //Раскомментируйте следующий фрагмент, подумайте - все ли корректно
        //Если есть некорректности, - исправьте

        if (!vInt.empty())
            vInt.front() = 1;


        //С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
        //На каждой итерации цикла следите за размером вектора с помощью методов
        //size(), capacity(), max_size() и выводите значения элементов.
        //
        //Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
        //напишите шаблон функции, которая для вектора, содержащего элементы любого типа
        //выводит его "реквизиты" и значения элементов на консоль.
        for (int i = 0; i < 10; ++i) {
            vInt.push_back(i);
            printVectorParameters(std::cout, vInt);
        }
    }

    //вектор вещественных - vDouble1 с заданным Вами начальным размером  и
    //проверьте результат с помощью созданного Вами шаблона. Как будут
    //проинициализированы элементы вектора?
    {
        vector<double> vDouble1(8);
        printVectorParameters(std::cout, vDouble1);
    }
    //вектор объектов типа MyString с начальным размером - 5 элементов
    //и инициализацией каждого элемента строкой "A"
    //C помощью функции at() а также с помощью оператора
    //индексирования []  измените значения каких-либо элементов.
    //Попробуйте "выйти" за границы вектора с помощью at() и
    //с помощью [].
    {
        vector<MyString> vMystring(5, MyString("A"));
        vMystring.at(1) = "B"; //ok
        vMystring[3] = "C"; //ok
//    vMystring.at(5) = "D"; // out_of_range
//	vMystring[7] = "E";  // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
        printVectorParameters(std::cout, vMystring);

        //вектор вещественных - vDouble3, который является копией элементов
        // [0,5) массива вещественных чисел dMas. Предворительно массив dMas
        //нужно создать и проинициализировать!
        double dMas[6] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
        vector<double> vDouble3;
        for (size_t i = 0; i < sizeof(dMas) / sizeof(double); i++) {
            vDouble3.push_back(dMas[i]);
        }
        printVectorParameters(std::cout, vDouble3);

        //вектор вещественных - vDouble4, который является копией элементов
        // [2,5) вектора vDouble3.
        vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.end());
        printVectorParameters(std::cout, vDouble4);

        //вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
        //будет вызван для каждого элемента?
        //b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
        vector<Point> vPoint1(3);
        printVectorParameters(std::cout, vPoint1);
        vector<Point> vPoint2(5, Point(1, 1));
        printVectorParameters(std::cout, vPoint2);
    }
    //вектор указателей на Point - vpPoint с начальным размером 5
    //Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
    {
        //Подсказка: для вывода на печать значений скорее всего Вам понадобится
        //а) специализация Вашей шаблонной функции
        //б) или перегрузка operator<< для Point*
        vector<Point *> vpPoint(5);
        for (size_t i = 0; i < vpPoint.size(); i++) {
            vpPoint[i] = new Point(i, i);
        }
        //Какие дополнительные действия нужно предпринять для такого вектора?
        for (size_t i = 0; i < vpPoint.size(); i++) {
            delete vpPoint[i];
        }
    };
    ///////////////////////////////////////////////////////////////////////
    //Резервирование памяти.
    //Подумайте, всегда ли верны приведенные ниже проверки?
    {
        size_t n = 10;
        vector<int> v(n);
        v.resize(n / 2);
        if (v.capacity() == n) {
            std::cout << true << std::endl;
        } else {
            std::cout << false << std::endl;
        }//true?
        // stl_vector.h - doc:
        /**
            ...
         *  This function will %resize the %vector to the specified
         *  number of elements.  If the number is smaller than the
         *  %vector's current size the %vector is truncated, otherwise
         *  default constructed elements are appended.
         */
    }

    {
        int n = 15;
        size_t m = 10;
        vector<int> v(n);
        v.reserve(m);
        if (v.capacity() == m) {
            std::cout << true << std::endl;
        } else {
            std::cout << false << std::endl;
        }//true?
        // if we try to reserve less space than a vector already has
        // capacity doesn't become smaller
    }

    {
        vector<int> v(3, 5);
        v.resize(4, 10); //значения? // 5, 5, 5, 10
        printVectorParameters(std::cout, v);
        v.resize(5); //значения? // 5, 5, 5, 10, 0
        printVectorParameters(std::cout, v);

    }

    //Создайте два "пустых" вектора с элементами
    //любого (но одного и того же) типа.
    //В первом векторе зарезервируйте память под 5 элементов, а потом заполните
    //его значениями с помощью push_back.
    //Второй вектор просто заполните значениями посредством push_back.
    //
    //Сравните размер, емкость векторов и значения элементов
    {
    vector<int> vInt11;
    vInt11.reserve(5);
    for (size_t i = 0; i < vInt11.capacity(); i++) {
        vInt11.push_back(i);
    }
    vector<int> vInt12;
    for (size_t i = 0; i < 5; i++) {
        vInt12.push_back(i);
    }

    printVectorParameters(std::cout, vInt11); // size: 5, capacity: 5
    printVectorParameters(std::cout, vInt12); // size: 5, capacity: 5
    //!!! shrink_to_fit - Уменьшение емкости вектора.
    //Для любого вектора из предыдущего задания требуется уменьшить емкость
    //до size.

    vInt11.shrink_to_fit();
    }
    //Создание "двухмерного вектора" - вектора векторов
    //Задан одномерный массив int ar[] = {11,2,4,3,5};
    //Создайте вектор векторов следующим образом:
    //вектор vv[0] - содержит 11 элементов со значением 11
    //vv[1] - содержит 2,2
    //vv[2] - содержит 4,4,4,4
    //...
    //Распечатайте содержимое такого двухмерного вектора по строкам
    {
        vector<vector<int>> vv = {vector<int>(11, 1), vector<int>(2, 2), vector<int>(4, 4)};
        printVectorParameters(std::cout, vv[0]);
        printVectorParameters(std::cout, vv[1]);
        printVectorParameters(std::cout, vv[2]);

        std::cout << std::endl;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Вставка элемента последовательности insert().
    //В вектор vChar2 вставьте в начало вектора символ только при
    //условии, что в векторе такого еще нет.
    {
        vector<char> vChar2;
        insertFirstIfDoesntContain(vChar2, 'c');
        insertFirstIfDoesntContain(vChar2, 'c');
        printVectorParameters(std::cout, vChar2);

        vChar2.push_back('d');
        vChar2.push_back('e');
        vChar2.push_back('f');
        printVectorParameters(std::cout, vChar2);

        //Вставьте перед каждым элементом вектора vChar2 букву 'W'
        for (vector<char>::iterator itb = vChar2.begin(); itb != vChar2.end();) {
            itb = vChar2.insert(itb, 'w');
            ++itb;
            ++itb;
        }
        printVectorParameters(std::cout, vChar2);
    }

///////////////////////////////////////////////////////////////////
    //Напишите функцию, которая должна удалять только повторяющиеся последовательности.
    //Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
    {
        const char *chars = "qwerrrrty12222r3";
        vector<char> vChar3(chars, chars + strlen(chars));
        printVectorParameters(std::cout, vChar3);

        for (vector<char>::iterator itb = vChar3.begin(); (itb + 1) != vChar3.end() && itb != vChar3.end();) {
            if (*itb == *(itb + 1)) {
                itb = vChar3.erase(itb);
            } else {
                ++itb;
            }
        }
        printVectorParameters(std::cout, vChar3);

        std::cout << std::endl;
    }
///////////////////////////////////////////////////////////////////

    //Удаление элемента последовательности erase()
    //Напишите функцию удаления из любого вектора всех дублей
    {
        const char *chars = "qwerr4rrty122422r3";
        vector<char> vChar(chars, chars + strlen(chars));
        removeDuplicates(vChar);
        printVectorParameters(std::cout, vChar);

///////////////////////////////////////////////////////////////////
    //Создайте новый вектор таким образом, чтобы его элементы стали
    //копиями элементов любого из созданных ранее векторов, но расположены
    //были бы в обратном порядке
        vector<char> vChar1(vChar.rbegin(), vChar.rend());
        printVectorParameters(std::cout, vChar1);
    }

///////////////////////////////////////////////////////////////////

    //Задание 1. Списки. Операции, характерные для списков.
    //Создайте пустой список из элементов Point - ptList1 и наполните
    //его значениями с помощью методов push_back(),
    //push_front, insert()


    //Напишите шаблон функции, которая будет выводить элементы
    //ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
    //vector и list. Подсказка - хотелось бы увидеть тип контейнера.


    //Сделайте любой из списков "реверсивным" - reverse()


    //Создайте список ptList2 из элементов Point таким образом, чтобы он стал
    //копией вектора элементов типа Point, но значения элементов списка располагались
    //бы в обратном порядке



    //Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
    //по возрастанию.
    //Подумайте: что должно быть перегружено в классе Point для того, чтобы
    //работала сортировка





    std::cout << std::endl;

    //Объедините отсортированные списки - merge(). Посмотрите: что
    //при этом происходит с каждым списком.


    std::cout << std::endl;

    //Исключение элемента из списка - remove()
    //Исключите из списка элемент с определенным значением.
    //Подумайте: что должно быть перегружено в классе Point?


    //Исключение элемента из списка, удовлетворяющего заданному условию:
    //любая из координат отрицательна - remove_if().


    //Исключение из списка подряд расположенных дублей - unique().

    std::cout << std::endl;

///////////////////////////////////////////////////////////////////
    //Задание 2.Очередь с двумя концами - контейнер deque

    //Создайте пустой deque с элементами типа Point. С помощью
    //assign заполните deque копиями элементов вектора. С помощью
    //разработанного Вами в предыдущем задании универсального шаблона
    //выведите значения элементов на печать



    //Создайте deque с элементами типа MyString. Заполните его значениями
    //с помощью push_back(), push_front(), insert()
    //С помощью erase удалите из deque все элементы, в которых строчки
    //начинаются с 'A' или 'a'




    return 0;
}

template<typename T>
void removeDuplicates(vector<T> &v) {
    for (typename vector<T>::iterator itb = v.begin(); itb != v.end() && (itb + 1) != v.end(); ++itb) {
        for (typename vector<T>::iterator internal = itb + 1; internal != v.end();) {
            if (*itb == *internal) {
                internal = v.erase(internal);
            } else {
                ++internal;
            }
        }
    }
}

void insertFirstIfDoesntContain(std::vector<char> &v, char c) {
    vector<char>::iterator itb = v.begin();
    for (; itb != v.end(); ++itb) {
        if (*itb == c) {
            return;
        }
    }
    v.insert(v.begin(), c);
}

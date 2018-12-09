//Исключения
#include "WrongIndexException.h"
//Шаблоны: 
//		шаблоны функций,
template<typename T>
void Swap(T &left, T &right) {
    T tmp = left;
    left = right;
    right = tmp;
};

//		шаблоны классов,
#include "MyStack.h"

//#include <stdexcept>
#include "myString.h"
#include "MyLinkedStack.h"
#include "RoundQueue.h"


int main() {
////////////////////////////////////////////////////////////////////////////
    //Тема. Шаблоны функций.
    //Создайте шаблон функции перестановки местами двух
    //значений - Swap(). Проверьте работоспособность созданного
    //шаблона с помощью приведенного ниже фрагмента кода.
    //Подсказка 1: объявление шаблона корректнее поместить в .h-файл.
    {
        int iX = 1, iY = -1;
        Swap(iX, iY);
        double dX = 0.5, dY = -5.5;
        Swap(dX, dY);
        std::cout << std::endl;

        //Подсказка 2: подумайте, что нужно реализовать, для того,
        //			чтобы следующий вызов работал с объектами MyString
        //			не только корректно, но и эффективно

        MyString str1("One"), str2("Two");
        Swap(str1, str2);
    }
    /////////////////////////////////////////////////////////////////////

    //Тема. Шаблоны классов.
    //Задание 1.
    //Создайте шаблон класса MyStack для хранения элементов любого типа T.
    //Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
    //			для хранения последовательно расположенных в памяти элементов
    //			является массив,
    //			2.для задания максимального размера стека может быть использован
    //			параметр-константа шаблона
    //			3.обязательными операциями со стеком являются "push" и "pop". Для
    //			того, чтобы гарантировать корректное выполнение этих операций
    //			хорошо было бы генерировать исключение в аварийной ситуации
    //			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
    //			мог читать/изменять значения только тех элементов, которые он формировал


    //С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
    //стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
    //push() и pop(), operator[]
    {
        MyStack<int, 4> iStack;
        try {
            iStack.push(1);
            iStack.push(2);
            iStack.push(3);
            iStack.push(2);
            iStack.push(3);
        }
        catch (const char *exception) {
            std::cout << exception << std::endl;
        }

        MyStack<MyString, 5> strStack;
        try {
            strStack.push(MyString("one"));
            strStack.push(MyString("two"));
            strStack.push(MyString("three"));
            strStack.push(MyString("one"));
            strStack.push(MyString("two"));
            strStack.push(MyString("three"));
        }
        catch (const char *exception) {
            std::cout << exception << std::endl;
        }
    }
    //Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы
    //для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
    //Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
    //пользователь
    {
        MyLinkedStack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        try {
            std::cout << stack.pop() << std::endl;
            std::cout << stack.pop() << std::endl;
            std::cout << stack.pop() << std::endl;
            std::cout << stack.pop() << std::endl;
        } catch (WrongIndexException *exc) { // TODO: doesn't work
            std::cout << exc->what() << std::endl;
        } catch (const char *msg) {
            std::cout << msg << std::endl;
        }

        MyLinkedStack<MyString> sStack;
        sStack.push(MyString("one"));
        sStack.push(MyString("two"));
        sStack.push(MyString("three"));
        sStack.push(MyString("one"));

        try {
            std::cout << sStack.pop() << std::endl;
            std::cout << sStack.pop() << std::endl;
        } catch (const char *msg) {
            std::cout << msg << std::endl;
        }

        std::cout << std::endl;
        sStack.printBackward(std::cout);
        std::cout << std::endl;
        sStack.print(std::cout);
    }
    //Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы
    //для хранения элементов использовался динамический массив.
    //При использовании массива следует учесть специфику очереди, то есть
    //когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
    //=> должен быть организован кольцевой буфер
    {
        RoundQueue<double> rq(3);
        rq.add(42.);
        rq.add(43.);
        rq.remove();
        rq.add(44.);
        rq.add(45.);
        rq.add(46.);

        try {
            std::cout << rq.remove() << std::endl;
            std::cout << rq.element() << std::endl;
            std::cout << rq.remove() << std::endl;
            std::cout << rq.remove() << std::endl;
            std::cout << rq.remove() << std::endl;
            std::cout << rq.remove() << std::endl;
        } catch (const char *msg) {
            std::cout << msg << std::endl;
        }

        RoundQueue<MyString> sRq(3);
        sRq.add(MyString("ONE"));
        MyString str = sRq.remove();
        std::cout << str << std::endl;
    }

    return 0;
}


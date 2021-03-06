// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


//#include <tchar.h>
//#define	  stop __asm nop
#include <iostream>
#include "Rect.h"
#include "Circle.h"
#include "MyByte.h"

using namespace std;

int main() {
    //Задание 1.Простое наследование.Аргументы конструктора,
    // передаваемые в базовый класс.

    //Создайте иерархию классов:
    //базовый класс Shape (который описывает любую фигуру)
    //и два производных класса Rect и Circle.
    //Подумайте: какие данные и методы нужно ввести в базовый
    //и производные классы (например, любую фигуру можно сделать
    //цветной => в базовом классе можно ввести переменную, которая
    //будет определять цвет фигуры.
    //Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
    Circle circle;
    Rect rect(0, 0, 2, 2, BLUE);
    cout << rect.GetSquare() << endl;
    //В конструкторах производных классов предусмотрите передачу
    //параметра-цвета конструктору базового класса.
    //При создании и уничтожении объекта производного типа определите
    //последовательность вызовов конструкторов и деструкторов базового
    //и производного классов
    cout << Circle(1, 2, 3).GetSquare() << endl;

    cout << "stop" << endl;
//////////////////////////////////////////////////////////////////////
    //Задание 2.Виртуальные функции.
    //2а) Модифицируйте классы Shape,Rect и Circle:
    //добавьте в каждый класс public метод void WhereAmI().
    //Реализация каждой функции должна выводить сообщение
    //следующего вида "Now I am in class Shape(Rect или Circle)".
    //Выполните приведенный фрагмент, объясните результат.
    {
        //Shape s;
        Rect r;
        Circle c;
        //Метод какого класса вызывается в следующих строчках???
        //s.WhereAmI();    //	Now I am in a class Shape
        r.WhereAmI();    //	Now I am in a class Rect
        c.WhereAmI();    //	Now I am in a class Circle
        cout << "stop" << endl;

		//Shape *pShape = &s;
        Shape *pRect = &r;
        Shape *pCircle = &c;
        //pShape->WhereAmI();    //	Now I am in a class Shape
        pRect->WhereAmI();    //	Now I am in a class Shape
        pCircle->WhereAmI(); //	Now I am in a class Shape
        cout << "stop" << endl;

        //Заполните ... согласно комментариям
        //Shape &rShape = s; //псевдоним s
        Shape &rRect = r; //псевдоним r
        Shape &rCircle = c; //псевдоним c
        //s.WhereAmI();    //вызов посредством rShape	???: Now I am in a class Shape
        r.WhereAmI();    //вызов посредством	rRect	???: Now I am in a class Rect
        c.WhereAmI(); //вызов посредством rCircle	???: Now I am in a class Circle
        cout << "stop" << endl;
    }

    //2б) Сделайте метод WhereAmI() виртуальным.
    //Снова выполните приведенный фрагмент, объясните разницу.

    {
        //Shape s;
        Rect r;
        Circle c;
        //Метод какого класса вызывается в следующих строчках???
        //s.WhereAmI();    //	Now I am in a class Shape
        r.WhereAmI();    //	Now I am in a class Rect
        c.WhereAmI();    //	Now I am in a class Circle
        cout << "stop" << endl;

        //Shape *pShape = &s;
        Shape *pRect = &r;
        Shape *pCircle = &c;
        //pShape->WhereAmI();    //	Now I am in a class Shape
        pRect->WhereAmI();    //	Now I am in a class Rect
        pCircle->WhereAmI(); //	Now I am in a class Circle
        cout << "stop" << endl;

        //Заполните ... согласно комментариям
        //Shape &rShape = s; //псевдоним s
        Shape &rRect = r; //псевдоним r
        Shape &rCircle = c; //псевдоним c
        //s.WhereAmI();    //вызов посредством rShape	???: Now I am in a class Shape
        r.WhereAmI();    //вызов посредством	rRect	???: Now I am in a class Rect
        c.WhereAmI(); //вызов посредством rCircle	???: Now I am in a class Circle
        cout << "stop" << endl;
    }

//////////////////////////////////////////////////////////////////////
    //Задание 3.Виртуальные деструкторы.
    //Модифицируйте классы:
    //a) введите соответствующие
    // деструкторы (без ключевого слова virtual).
    //Реализация каждого деструктора
    //должна выводить сообщение следующего вида
    // "Now I am in Shape's destructor!" или
    // "Now I am in Rect's destructor!"
    //Выполните фрагмент. Объясните результат.
    {
        //Shape s; // Now I am in Circle's destructor!
        //  Now I am in Shape's destructor!
        Rect r; // Now I am in Rect's destructor!
        //  Now I am in Shape's destructor!

        Circle c; // Now I am in Shape's destructor!
    }
    cout << "stop" << endl;
    // b) Добавьте в объявление деструкторов ключевое слово virtual
    //Выполните фрагмент.Объясните разницу.
    {
        //Shape s; // Now I am in Circle's destructor!
        //  Now I am in Shape's destructor!
        Rect r; // Now I am in Rect's destructor!
        //  Now I am in Shape's destructor!

        Circle c; // Now I am in Shape's destructor!
    }
    cout << "stop" << endl;

    //Подумайте: какие конструкторы вызываются в следующей строке?
    //Если в разработанных классах каких-то конструкторов
    //не хватает - реализуйте
    //Если Вы считаете, что в приведенном фрагменте чего-то
    //не хватает - добавьте
    {
        Rect r(0, 0, 2, 3);
        Shape *ar[] = {/*new Shape(r), */new Rect(r), new Circle(r), new Circle()};
        //Вызовите для каждого элемента массива метод WhereAmI()
        for (int i = 0; i < 3; ++i) {
            ar[i]->WhereAmI();
			delete ar[i];
        }

        cout << "stop" << endl;
    }

    //Задание 4*. В чем заключается отличие 1) и 2)
    {
        cout << "Task 4" << endl;
        Shape *pShapes = new Rect[10];//1) // Shape* -> Rect*
        Rect *pRects = new Rect[10];//2)

        //Попробуйте вызвать метод WhereAmI() для каждого элемента обоих массивов -
        //в чем заключается проблема???
        for (int i = 0; i < 10; ++i) {
            pShapes[i].Shape::WhereAmI();
            pRects[i].WhereAmI();
        }
        //Освободите динамически захваченную память
        delete[] pShapes;
        delete[] pRects;
        cout << "stop" << endl;
    }


//////////////////////////////////////////////////////////////////////
    //Задание 5.Виртуальные функции и оператор разрешения области видимости.

    {
        cout << "Task 5" << endl;
        Rect r;
        Shape *p = &r;
        p->WhereAmI(); // Now I am in a class Rect

        //5a Оператор разрешения области видимости.
        //Посредством объекта r и указателя p вызовите виртуальную функцию
        //WhereAmI()класса Shape

        //static_cast<Shape>(*p).WhereAmI();
		p->Shape::WhereAmI();

        cout << "stop" << endl;
    }

//////////////////////////////////////////////////////////////////////
    //Задание 6.Чисто виртуальные функции.
    //Введите в базовый класс метод void Inflate(int); Подумайте:
    //можно ли реализовать такой метод для базового класса? => как его нужно объявить.
    //Реализуйте этот метод для производных классов.
    {
        Rect r;
        Shape *p = &r;
        p->Inflate(5);
        Circle c;
        p = &c;
        p->Inflate(5);
    }

//////////////////////////////////////////////////////////////////////

	//Задание 7.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

	MyByte byte(0xff);
	byte.ShowHex();
	byte.ShowOct();
	byte.ShowBin();






    return 0;
}//endmain


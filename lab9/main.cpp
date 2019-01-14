// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>

#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <iterator>
#include <utility>

#include "Functions.h"
#include "Point.h"

using namespace std;

int main() {

    //Напишите шаблон функции для вывода значений stack, queue, priority_queue
    //обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для
    //получения значений

    ////////////////////////////////////////////////////////////////////////////////////
    //stack

    //Создайте стек таким образом, чтобы
    //а) элементы стека стали копиями элементов вектора
    //б) при выводе значений как вектора, так и стека порядок значений был одинаковым
	
    {
 
		vector<int> vec = {1, 2, 3, 4};
        stack<int, vector<int>> st(vector<int>(vec.rbegin(), vec.rend()));
        //for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        //    st.push(*it);
        //}
        print_container(vec);
        print_adapter(st);
    }
	
    ////////////////////////////////////////////////////////////////////////////////////
    //queue

    //Создайте очередь, которая содержит указатели на объекты типа Point,
    //при этом явно задайте базовый контейнер.
    //Измените значения первого и последнего элементов посредством front() и back()
    //Подумайте, что требуется сделать при уничтожении такой очереди?
    {
        queue<Point *, deque<Point *>> queue1;
        queue1.push(new Point(1, 1));
        queue1.push(new Point(2, 2));
        queue1.push(new Point(3, 3));
        queue1.push(new Point(4, 4));
        delete queue1.front();
        queue1.front() = new Point(42, 42);
        delete queue1.back();
        queue1.back() = new Point(43, 43);

		print_adapter(queue1);

        //print_queue_of_pointers(queue1);
		print_adapter(queue1);
        while (!queue1.empty()) {
            delete queue1.front();
            queue1.pop();
        }
        cout << endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////
    //priority_queue
    //а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
    //б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
    //в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
    //		что сравнивается при вставке?
    auto cmp = [](const char *left, const char *right) { return (strcmp(left, right) > 0); };
    {
        priority_queue<const char *, vector<const char *>, decltype(cmp)> qPChar(cmp);
        qPChar.push("one");
        qPChar.push("two");
        qPChar.push("three");
        qPChar.push("0");
        qPChar.push("1");
        qPChar.push("22");

        print_adapter(qPChar);
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //set
    //a) создайте множество с элементами типа Point - подумайте, что необходимо определить
    //		в классе Point (и каким образом)
    //б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
    //в) попробуйте изменить любое значение...
    {
        set<Point> set1;
        set1.insert(Point(1, 1));
        set1.insert(Point(2, 2));
        set1.insert(Point(3, 3));
        set1.insert(Point(4, 4));
        print_container(set1);
        //    *(set1.begin()) = Point(42, 42);
        //    print_container(set1);

        //г) Создайте два множества, которые будут содержать одинаковые значения
        //		типа int, но занесенные в разном порядке
        //д) Вставьте в любое множество диапазон элементов из любого другого
        //	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
        set<int> sInt = {1, 2, 3, 4};
        print_container(sInt);
        set<int> sInt2(sInt.rbegin(), sInt.rend());
        print_container(sInt2); // set has no ordering
        int arr[] = {4, 5, 6};
        sInt.insert(arr, arr + sizeof(arr) / sizeof(int));
        print_container(sInt); // set can't have duplicates
    }
    ////////////////////////////////////////////////////////////////////////////////////
    //map, multiset
    //а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
    //	при этом строки задаются строковыми литералами
    //б) заполните контейнер значениями посредством operator[] и insert()
    //в) распечатайте содержимое

    //г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
    {
		map<const char *, int, decltype(cmp)> map1 = {
                make_pair("Doe", 150000),
                make_pair("Norris", 180000),
        };
        map1["Harris"] = 100000;
        print_map(map1);
        map1.insert(pair<const char *, int>("Harris2", map1["Harris"]));
        map1.erase("Harris");
        print_map(map1);

        cout << endl;
    }
    //д) Сформируйте любым способом вектор с элементами типа string.
    //Создайте (и распечатайте для проверки) map<string, int>, который будет
    //содержать упорядоченные по алфавиту строки и
    //количество повторений каждой строки в векторе
    {
        vector<string> vString = {"one", "two", "three", "three"};
        map<string, int> map2;
        for (vector<string>::iterator it = vString.begin(); it != vString.end(); ++it) {
            map2[*it]++;
        }
        print_map(map2); // TODO
    }
	string * p = new string("asdf");
	const  type_info&ti = typeid (p);
	cout << ti.name();
    //е)
    //задан массив:
    //const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
    //создайте map, в котором каждой букве будет соответствовать совокупность
    //лексиграфически упорядоченных слов, начинающихся с этой буквы.
    //Подсказка: не стоит хранить дубли одной и той же строки

    //'A' -  "Abba" "Alfa"
    //'B' -  "Beauty" "Beta"  ...
    //...
    {
        const char *words[] = {"Abba", "Alfa", "Beta", "Beauty", "Beauty", "Beauty"};
        map<char, set<const char *>> mapWords;
        for (int i = 0; i < sizeof(words) / sizeof(char *); ++i) {
            mapWords[words[i][0]].insert(words[i]);
        }
        print_map(mapWords);

        //ж)
        //создайте структуру данных, которая будет хранить информацию о студенческих группах.
        //Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом
        //фамилии могут дублироваться
        //Сами группы тоже должны быть упорядочены по номеру
        //
        //номера
        {
            //typedef multiset<const char *, std::greater<const char *>> MULTISET_CHARS_DESC;
			typedef multiset<const char *> MULTISET_CHARS_DESC;
            MULTISET_CHARS_DESC group1;
            group1.insert("Иванов");
            group1.insert("Иванов");
            group1.insert("Петров");
            group1.insert("Сидоров");
            MULTISET_CHARS_DESC group2;
            group2.insert("Фёдоров");
            group2.insert("Фёдоров");
            group2.insert("Фёдоров");
            group2.insert("Укупник");
            group2.insert("Стаценко");

            map<int, MULTISET_CHARS_DESC> groups;
            groups[41] = group1;
            groups[42] = group2;
            print_map(groups);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //multimap
    //а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
    //		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
    //б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью
    //		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
    //в) Выведите все содержимое словаря на экран
    //г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
    //		итераторов можно использовать методы lower_bound() и upper_bound()
    {
        multimap<string, string> dictionary = {
                make_pair("free", "свободный"),
                make_pair("free", "бесплатный"),
                make_pair("master", "мастер"),
                make_pair("master", "хозяин"),
                make_pair("master", "наставник"),
        };
        dictionary.insert(make_pair("strange", "чужой"));
        dictionary.insert(make_pair("strange", "странный"));
        print_map(dictionary);

        print_map_by_key(dictionary, string("strange"));
        print_map_by_key(dictionary, string("master"));
        print_map_by_key(dictionary, string("free"));

        cout << endl;
    }
    return 0;
}

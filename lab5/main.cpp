
#include <iostream>
#include "MyString.h"

int main() {
    MyString str;
    MyString str_("");

    MyString str1("one");
    MyString str2("two");
    MyString str3("three");
    MyString str4("four");
    MyString str5("five");

    MyString str31("three");
    MyString str21("two");

    MyString copied = str1;
    MyString moved = std::move(str2);

    MyString::printAll();

    MyString strd1("1");
    MyString strd2("2");
    MyString strd3("3");
    MyString strd4("4");
    MyString strd5("5");

    MyString strl3("c");
    MyString strl2("b");
    MyString strl4("d");
    MyString strl1("a");
    MyString strl5("e");

    MyString::sort();
    MyString::printAll();

    MyString::uppercaseAll();
    MyString::printAll();

    std::cout << str1 << std::endl;
}

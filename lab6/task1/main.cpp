#include "Stroka.h"
#include <iostream>
using namespace std;

int main() {
    Stroka s1("qwert"), s3, s4(s1), s5;

    // Ввод строки в объект s3
    s3.vvod();

    // Присваивание объекту s3 новой строки
    s3 = Stroka("asdfg");

    cout << "s3 = ";
    s3.vyvod();
    cout << endl;

    // Сцепление строк
    s5 = s1 + s3 + s4;

    cout << "Dlina s5 = " << s5.dlina() << endl;

    cout << "s5 = ";
    s5.vyvod();
    cout << endl;

    // Сравнение строк
    if (s1 == s5)
        cout << "stroki s1 i s5 ravny" << endl;
    else if (s1 == s4)
        cout << "stroki s1 i s4 ravny" << endl;
    else
        cout << "stroki ne ravny" << endl;

    return 0;
}

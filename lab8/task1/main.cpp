#include "Stroka.h"
#include <iostream>
using namespace std;

int main() {
    Stroka s1("hello"), s2, s3;

    // Ввод строки через оператор >>
    cout << "Enter s2: ";
    cin >> s2;

    // Сцепление строк
    s3 = s1 + s2;

    // Вывод строк через оператор <<
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "Length of s3 = " << s3.dlina() << endl;

    if (s1 == s2)
        cout << "s1 and s2 are equal" << endl;
    else
        cout << "s1 and s2 are not equal" << endl;

    return 0;
}

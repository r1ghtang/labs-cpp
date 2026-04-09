#include "Stroka.h"
#include <iostream>
using namespace std;

int main() {
    Stroka s1("qwert");
    Stroka s2("asd");
    Stroka s3;

    s3 = s1 + s2;

    cout << "s1 = ";
    s1.vyvod();
    cout << endl;

    cout << "s2 = ";
    s2.vyvod();
    cout << endl;

    cout << "s3 = ";
    s3.vyvod();
    cout << endl;

    cout << "dlina s3 = " << s3.dlina() << endl;

    if (s1 == s2)
        cout << "s1 and s2 are equal" << endl;
    else
        cout << "s1 and s2 are not equal" << endl;

    return 0;
}

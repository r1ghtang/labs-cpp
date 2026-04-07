#include <iostream>
#include <cstring> // библиотека строк
using namespace std;

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";

    // длина строки
    cout << "Length str1 = " << strlen(str1) << endl;
    cout << "Length str2 = " << strlen(str2) << endl;

    // копирование строки
    strcpy(str1, str2);
    cout << "After copy str1 = " << str1 << endl;

    // сравнение строк
    int res = strcmp(str1, str2);
    cout << "Compare result = " << res << endl;

    // сцепление строк
    strcat(str1, "!!!");
    cout << "After concat str1 = " << str1 << endl;

    return 0;
}

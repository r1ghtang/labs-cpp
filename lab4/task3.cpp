#include <iostream>
#include <cstdlib> // malloc, free
using namespace std;

int main() {
    // выделяем память под строки
    char* str1 = (char*)malloc(100);
    char* str2 = (char*)malloc(100);

    // ввод строк
    cout << "Enter str1: ";
    cin >> str1;

    cout << "Enter str2: ";
    cin >> str2;

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    // освобождаем память
    free(str1);
    free(str2);

    return 0;
}

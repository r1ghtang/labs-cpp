#include <iostream>
using namespace std;

// длина строки (способ 1)
int dlina1(char* s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

// длина строки (способ 2)
int dlina2(char* s) {
    int count = 0;
    for (; *s != '\0'; s++) count++;
    return count;
}

// длина строки (способ 3 - рекурсия)
int dlina3(char* s) {
    if (*s == '\0') return 0;
    return 1 + dlina3(s + 1);
}

// копирование строки
void kopir(char* dest, char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// сравнение строк
void sravn(char* s1, char* s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            cout << "Strings are NOT equal" << endl;
            return;
        }
        s1++;
        s2++;
    }
    cout << "Strings are equal" << endl;
}

// сцепление строк
void konkat(char* s1, char* s2) {
    while (*s1) s1++; // идём в конец первой строки
    while (*s2) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int main() {
    char str1[100] = "qwerty";
    char str2[100] = "123456";

    // длина строки
    cout << "dlina1 = " << dlina1(str1) << endl;
    cout << "dlina2 = " << dlina2(str1) << endl;
    cout << "dlina3 = " << dlina3(str1) << endl;

    // копирование
    kopir(str1, str2);
    cout << "After copy str1 = " << str1 << endl;

    // сравнение
    sravn(str1, str2);

    // сцепление
    konkat(str1, str2);
    cout << "After concat str1 = " << str1 << endl;

    return 0;
}

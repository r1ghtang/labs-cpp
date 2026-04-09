#include "Stroka.h"

// Своя функция длины строки
int Stroka::myLen(const char* s) const {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

// Своя функция копирования
void Stroka::myCopy(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Своя функция сравнения
int Stroka::myCompare(const char* s1, const char* s2) const {
    while (*s1 && *s2) {
        if (*s1 != *s2) return 0;
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0');
}

// Своя функция сцепления
void Stroka::myConcat(char* dest, const char* src) {
    while (*dest) dest++;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Конструктор без параметров
Stroka::Stroka() {
    str = new char[1];
    str[0] = '\0';
}

// Конструктор с параметром
Stroka::Stroka(const char* s) {
    str = new char[myLen(s) + 1];
    myCopy(str, s);
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    str = new char[myLen(s.str) + 1];
    myCopy(str, s.str);
}

// Деструктор
Stroka::~Stroka() {
    delete[] str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        delete[] str;
        str = new char[myLen(s.str) + 1];
        myCopy(str, s.str);
    }
    return *this;
}

// Оператор сцепления
Stroka Stroka::operator+(const Stroka& s) const {
    Stroka temp;
    delete[] temp.str;

    int len1 = myLen(str);
    int len2 = myLen(s.str);

    temp.str = new char[len1 + len2 + 1];
    temp.str[0] = '\0';

    myCopy(temp.str, str);
    temp.myConcat(temp.str, s.str);

    return temp;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& s) const {
    return myCompare(str, s.str);
}

// Длина строки
int Stroka::dlina() const {
    return myLen(str);
}

// Ввод строки
void Stroka::vvod() {
    char buffer[256];
    cin >> buffer;

    delete[] str;
    str = new char[myLen(buffer) + 1];
    myCopy(str, buffer);
}

// Вывод строки
void Stroka::vyvod() const {
    cout << str;
}

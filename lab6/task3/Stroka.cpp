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
        if (*s1 != *s2) {
            return 0;
        }
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
    str[0] = '\0';
}

// Конструктор с параметром
Stroka::Stroka(const char* s) {
    myCopy(str, s);
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    myCopy(str, s.str);
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        myCopy(str, s.str);
    }
    return *this;
}

// Оператор сцепления
Stroka Stroka::operator+(const Stroka& s) const {
    Stroka temp(*this);
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

// Ввод
void Stroka::vvod() {
    cin >> str;
}

// Вывод
void Stroka::vyvod() const {
    cout << str;
}

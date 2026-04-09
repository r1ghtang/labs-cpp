#include "Stroka.h"
#include <cstring>

// Конструктор без параметров
Stroka::Stroka() {
    str[0] = '\0';
}

// Конструктор с параметром
Stroka::Stroka(const char* s) {
    strcpy(str, s);
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        strcpy(str, s.str);
    }
    return *this;
}

// Оператор сцепления
Stroka Stroka::operator+(const Stroka& s) const {
    Stroka temp(*this);
    strcat(temp.str, s.str);
    return temp;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& s) const {
    return strcmp(str, s.str) == 0;
}

// Длина строки
int Stroka::dlina() const {
    return strlen(str);
}

// Ввод
void Stroka::vvod() {
    cin >> str;
}

// Вывод
void Stroka::vyvod() const {
    cout << str;
}

// Перегруженный оператор ввода
istream& operator>>(istream& in, Stroka& s) {
    in >> s.str;
    return in;
}

// Перегруженный оператор вывода
ostream& operator<<(ostream& out, const Stroka& s) {
    out << s.str;
    return out;
}

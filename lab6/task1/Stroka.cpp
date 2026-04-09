#include "Stroka.h"
#include <cstring>

// Конструктор без параметров
Stroka::Stroka() {
    str[0] = '\0'; // делаем строку пустой
}

// Конструктор с параметром
Stroka::Stroka(const char* s) {
    strcpy(str, s); // копируем строку в поле класса
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str); // копируем строку из другого объекта
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
    Stroka temp(*this);   // создаём копию текущего объекта
    strcat(temp.str, s.str); // дописываем вторую строку
    return temp;
}

// Оператор сравнения
bool Stroka::operator==(const Stroka& s) const {
    return strcmp(str, s.str) == 0;
}

// Метод длины строки
int Stroka::dlina() const {
    return strlen(str);
}

// Метод ввода
void Stroka::vvod() {
    cin >> str;
}

// Метод вывода
void Stroka::vyvod() const {
    cout << str;
}

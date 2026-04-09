#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char str[80]; // массив для хранения строки

public:
    // Конструктор без параметров
    Stroka();

    // Конструктор с параметром
    Stroka(const char* s);

    // Конструктор копирования
    Stroka(const Stroka& s);

    // Оператор присваивания
    Stroka& operator=(const Stroka& s);

    // Оператор сцепления
    Stroka operator+(const Stroka& s) const;

    // Оператор сравнения
    bool operator==(const Stroka& s) const;

    // Метод длины строки
    int dlina() const;

    // Обычные методы ввода-вывода
    void vvod();
    void vyvod() const;

    // Дружественные операторы потокового ввода и вывода
    friend istream& operator>>(istream& in, Stroka& s);
    friend ostream& operator<<(ostream& out, const Stroka& s);
};

#endif

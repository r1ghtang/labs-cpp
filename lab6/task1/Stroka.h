#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char str[80]; // массив символов для хранения строки

public:
    // Конструктор без параметров
    Stroka();

    // Конструктор с параметром
    Stroka(const char* s);

    // Конструктор копирования
    Stroka(const Stroka& s);

    // Оператор присваивания
    Stroka& operator=(const Stroka& s);

    // Оператор сцепления строк
    Stroka operator+(const Stroka& s) const;

    // Оператор сравнения
    bool operator==(const Stroka& s) const;

    // Метод определения длины строки
    int dlina() const;

    // Метод ввода строки
    void vvod();

    // Метод вывода строки
    void vyvod() const;
};

#endif

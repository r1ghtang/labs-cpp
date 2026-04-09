#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka {
private:
    char* str;

    int myLen(const char* s) const;
    void myCopy(char* dest, const char* src);
    int myCompare(const char* s1, const char* s2) const;
    void myConcat(char* dest, const char* src);

public:
    Stroka();
    Stroka(const char* s);
    Stroka(const Stroka& s);

    ~Stroka(); // деструктор

    Stroka& operator=(const Stroka& s);
    Stroka operator+(const Stroka& s) const;
    bool operator==(const Stroka& s) const;

    int dlina() const;
    void vvod();
    void vyvod() const;
};

#endif

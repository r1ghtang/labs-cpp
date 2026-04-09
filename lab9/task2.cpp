#include <iostream>
#include <cstring>
using namespace std;

// Шаблон функции: максимум из двух значений
template <class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

// Специализация для строк char*
// strcmp > 0 значит первая строка больше второй
char* getmax(char* s1, char* s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

// Шаблон функции: максимум в массиве
template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    for (size_t i = 0; i < size; i++) {
        if (t[i] > retval) {
            retval = t[i];
        }
    }
    return retval;
}

// Шаблон класса стек
template <class T>
class Tstack {
protected:
    int numItem;   // количество элементов в стеке
    T* item;       // массив элементов

public:
    // Конструктор
    Tstack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }

    // Деструктор
    ~Tstack() {
        delete[] item;
    }

    // Добавление элемента в стек
    void push(T t) {
        item[numItem++] = t;
    }

    // Извлечение элемента из стека
    T pop() {
        return item[--numItem];
    }
};

int main() {
    int i1 = 3, i2 = 5;
    int mas[] = {3, 9, 5, 8};

    char s1[] = "stroka1";
    char s2[] = "stroka2";

    cout << "max int = " << getmax(i1, i2) << endl;
    cout << "max in array = " << getmax(mas, 4) << endl;
    cout << "max str = " << getmax(s1, s2) << endl;

    cout << "\nStack demo:" << endl;
    Tstack<int> st_int(10);

    st_int.push(33);
    st_int.push(45);

    cout << "Values in stack: ";
    cout << st_int.pop() << " " << st_int.pop() << endl;

    return 0;
}

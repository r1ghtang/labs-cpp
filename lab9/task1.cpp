#include <iostream>
using namespace std;

// Пользовательский класс Money
class Money {
private:
    long dollars;
    int cents;

public:
    // Конструктор без параметров
    Money() {
        dollars = 0;
        cents = 0;
    }

    // Конструктор с параметрами
    Money(long d, int c) {
        dollars = d;
        cents = c;
    }

    // Оператор сравнения "больше"
    // Нужен для работы шаблона Sort
    bool operator>(const Money& other) const {
        if (dollars > other.dollars) return true;
        if (dollars == other.dollars && cents > other.cents) return true;
        return false;
    }

    // Дружественный оператор вывода
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << "$" << m.dollars << "." << m.cents;
        return os;
    }
};

// Шаблон функции сортировки пузырьком
template <class T>
void Sort(T array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (array[j - 1] > array[j]) {
                T temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

int main() {
    // Массив объектов пользовательского класса
    Money mas[] = {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };

    int n = sizeof(mas) / sizeof(mas[0]);

    cout << "Before sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << mas[i] << endl;
    }

    // Вызываем шаблон сортировки
    Sort(mas, n);

    cout << "\nAfter sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << mas[i] << endl;
    }

    return 0;
}

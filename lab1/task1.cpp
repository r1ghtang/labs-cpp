#include <iostream>
using namespace std;

// Функция power вычисляет степень числа x^n
int power(int x, int n) {
    int p = 1; // переменная для хранения результата

    // цикл умножает число x само на себя n раз
    for (int i = 0; i < n; i++) {
        p *= x;
    }

    return p; // возвращаем результат в main
}

int main() {
    int x; // переменная для основания

    // просим пользователя ввести число
    cout << "Enter x: ";
    cin >> x;

    // цикл от 0 до 9 (вычисляем степени)
    for (int i = 0; i < 10; i++) {

        // выводим номер степени и результат
        cout << "i = " << i << ", k = " << power(x, i) << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Функция вывода массива
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int mas[] = {7, 2, 9, 4, 1, 8, 3, 6, 5};
    int n = sizeof(mas) / sizeof(mas[0]);

    cout << "Before sort:" << endl;
    printArray(mas, n);

    // Сортировка:
    // чётные по возрастанию
    // нечётные по убыванию
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            // если оба четные - сортируем по возрастанию
            if (mas[i] % 2 == 0 && mas[j] % 2 == 0) {
                if (mas[i] > mas[j]) {
                    int temp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = temp;
                }
            }

            // если оба нечетные - сортируем по убыванию
             if (mas[i] % 2 != 0 && mas[j] % 2 != 0) {
                if (mas[i] < mas[j]) {
                    int temp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = temp;
                }
            }
        }
    }

    cout << "After sort:" << endl;
    printArray(mas, n);

    return 0;
}

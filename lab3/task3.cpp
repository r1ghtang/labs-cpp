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
    // четные по возрастанию
    // нечетные по убыванию
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            bool even1 = (mas[j] % 2 == 0);
            bool even2 = (mas[j + 1] % 2 == 0);

            // Если оба четные, сортируем по возрастанию
            if (even1 && even2 && mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }

            // Если оба нечетные, сортируем по убыванию
            if (!even1 && !even2 && mas[j] < mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "After sort:" << endl;
    printArray(mas, n);

    return 0;
}

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
    // Исходный массив
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};

    // Вычисляем количество элементов массива
    int n = sizeof(mas) / sizeof(mas[0]);

    cout << "Before sort:" << endl;
    printArray(mas, n);

    // Сортировка по возрастанию методом выбора
    for (int i = 0; i < n - 1; i++) {
        int imin = i; // индекс минимального элемента

        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[imin]) {
                imin = j;
            }
        }

        // Меняем местами текущий элемент и найденный минимум
        int temp = mas[i];
        mas[i] = mas[imin];
        mas[imin] = temp;
    }

    cout << "After sort:" << endl;
    printArray(mas, n);

    return 0;
}

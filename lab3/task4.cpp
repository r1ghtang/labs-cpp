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
    int mas[] = {9, 4, 7, 2, 8, 1, 6, 3, 5};
    int n = sizeof(mas) / sizeof(mas[0]);

    int N1, N2;

    cout << "Before sort:" << endl;
    printArray(mas, n);

    cout << "Enter N1 and N2: ";
    cin >> N1 >> N2;

    // Проверка границ
    if (N1 < 0 || N2 >= n || N1 > N2) {
        cout << "Wrong interval" << endl;
        return 0;
    }

    // Сортировка по возрастанию только в указанном интервале
    for (int i = N1; i < N2; i++) {
        for (int j = N1; j < N2 - (i - N1); j++) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "After sort in interval:" << endl;
    printArray(mas, n);

    return 0;
}

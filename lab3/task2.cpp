#include <iostream>
using namespace std;

// Функция вывода массива
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Пузырьковая сортировка
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Быстрая сортировка
void quickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int middle = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < middle) i++;
        while (a[j] > middle) j--;

        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

int main() {
    int a1[] = {7, 2, 9, 1, 5, 3};
    int a2[] = {7, 2, 9, 1, 5, 3};
    int n = 6;

    cout << "Original array:" << endl;
    printArray(a1, n);

    bubbleSort(a1, n);
    cout << "After bubble sort:" << endl;
    printArray(a1, n);

    quickSort(a2, 0, n - 1);
    cout << "After quick sort:" << endl;
    printArray(a2, n);

    return 0;
}

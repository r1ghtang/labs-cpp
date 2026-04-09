#include <iostream>
using namespace std;

// Шаблон класса стек
template <class T>
class Tstack {
private:
    int numItem;   // текущее количество элементов
    int maxSize;   // размер стека
    T* item;       // массив элементов

public:
    // Конструктор
    Tstack(int size = 10) {
        maxSize = size;
        numItem = 0;
        item = new T[maxSize];
    }

    // Деструктор
    ~Tstack() {
        delete[] item;
    }

    // Добавление элемента в стек
    void push(T t) {
        if (numItem < maxSize) {
            item[numItem++] = t;
        }
    }

    // Извлечение элемента из стека
    T pop() {
        return item[--numItem];
    }

    // Проверка на пустоту
    bool empty() {
        return numItem == 0;
    }
};

int main() {
    // Пример входного состава
    int train[] = {1, 5, 3};
    int n = sizeof(train) / sizeof(train[0]);

    // Создаём стек
    Tstack<int> deadEnd(n);

    cout << "Input: ";
    for (int i = 0; i < n; i++) {
        cout << train[i] << " ";
    }
    cout << endl;

    // Загоняем вагоны в тупик (стек)
    for (int i = 0; i < n; i++) {
        deadEnd.push(train[i]);
    }

    cout << "Output: ";
    // Выводим вагоны из стека
    while (!deadEnd.empty()) {
        cout << deadEnd.pop() << " ";
    }
    cout << endl;

    return 0;
}

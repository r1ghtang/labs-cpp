#include <iostream>
using namespace std;

// Шаблон класса односвязного списка
template <class T>
class OneList {
private:
    // Внутренний узел списка
    struct Node {
        T data;
        Node* next;
    };

    Node* head; // начало списка
    Node* tail; // конец списка

public:
    // Конструктор
    OneList() {
        head = nullptr;
        tail = nullptr;
    }

    // Деструктор
    ~OneList() {
        clear();
    }

    // Очистка списка
    void clear() {
        Node* pv = head;
        while (pv) {
            Node* temp = pv;
            pv = pv->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Добавление элемента в конец
    void add(T value) {
        Node* pv = new Node;
        pv->data = value;
        pv->next = nullptr;

        if (!head) {
            head = tail = pv;
        }
        else {
            tail->next = pv;
            tail = pv;
        }
    }

    // Удаление элемента по значению
    bool remove(T key) {
        Node* pv = head;
        Node* prev = nullptr;

        while (pv) {
            if (pv->data == key) {
                if (pv == head) {
                    head = pv->next;
                    if (pv == tail) {
                        tail = nullptr;
                    }
                }
                else {
                    prev->next = pv->next;
                    if (pv == tail) {
                        tail = prev;
                    }
                }

                delete pv;
                return true;
            }

            prev = pv;
            pv = pv->next;
        }

        return false;
    }

    // Поиск элемента
    bool find(T key) {
        Node* pv = head;
        while (pv) {
            if (pv->data == key) {
                return true;
            }
            pv = pv->next;
        }
        return false;
    }

    // Вывод списка
    void print() {
        Node* pv = head;
        while (pv) {
            cout << pv->data << " ";
            pv = pv->next;
        }
        cout << endl;
    }
};

int main() {
    OneList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "List: ";
    list.print();

    cout << "Find 20: " << list.find(20) << endl;
    cout << "Find 99: " << list.find(99) << endl;

    list.remove(30);

    cout << "After remove 30: ";
    list.print();

    return 0;
}

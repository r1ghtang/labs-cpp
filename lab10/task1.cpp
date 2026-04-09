#include <iostream>
using namespace std;

// Узел односвязного списка
struct Node {
    int d;         // данные
    Node* next;    // указатель на следующий элемент
};

// Создание первого элемента списка
Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    return pv;
}

// Добавление элемента в конец списка
void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;

    (*pend)->next = pv;
    *pend = pv;
}

// Поиск элемента по ключу
Node* find(Node* pbeg, int key) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == key) {
            return pv;
        }
        pv = pv->next;
    }
    return nullptr;
}

// Удаление элемента по ключу
int remove(Node** pbeg, Node** pend, int key) {
    Node* pv = *pbeg;
    Node* prev = nullptr;

    while (pv) {
        if (pv->d == key) {
            // Если удаляем первый элемент
            if (pv == *pbeg) {
                *pbeg = pv->next;

                // Если список стал пустым
                if (pv == *pend) {
                    *pend = nullptr;
                }
            }
            else {
                prev->next = pv->next;

                // Если удаляем последний элемент
                if (pv == *pend) {
                    *pend = prev;
                }
            }

            delete pv;
            return 1;
        }

        prev = pv;
        pv = pv->next;
    }

    return 0;
}

// Вставка нового элемента после элемента с ключом key
Node* insert(Node* pbeg, Node** pend, int key, int d) {
    Node* pkey = find(pbeg, key);

    if (!pkey) {
        return nullptr;
    }

    Node* pv = new Node;
    pv->d = d;
    pv->next = pkey->next;
    pkey->next = pv;

    // Если вставка была после последнего элемента
    if (pkey == *pend) {
        *pend = pv;
    }

    return pv;
}

// Вывод списка
void printList(Node* pbeg) {
    Node* pv = pbeg;
    while (pv) {
        cout << pv->d << " ";
        pv = pv->next;
    }
    cout << endl;
}

int main() {
    // Формирование первого элемента списка
    Node* pbeg = first(1);

    // Пока в списке один элемент, начало и конец совпадают
    Node* pend = pbeg;

    // Добавляем в конец элементы 2, 3, 4, 5
    for (int i = 2; i <= 5; i++) {
        add(&pend, i);
    }

    // Вставляем 200 после элемента 2
    insert(pbeg, &pend, 2, 200);

    // Удаляем элемент 5
    if (!remove(&pbeg, &pend, 5)) {
        cout << "Element not found" << endl;
    }

    // Выводим список
    cout << "List: ";
    printList(pbeg);

    return 0;
}

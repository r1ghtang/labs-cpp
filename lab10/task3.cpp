#include <iostream>
#include <string>
using namespace std;

// Структура с информацией об автобусе
struct Bus {
    int number;         // номер автобуса
    string driver;      // фамилия и инициалы водителя
    int route;          // номер маршрута

    // Оператор сравнения для поиска по номеру
    bool operator==(const Bus& other) const {
        return number == other.number;
    }
};

// Односвязный список автобусов
class BusList {
private:
    struct Node {
        Bus data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    BusList() {
        head = nullptr;
        tail = nullptr;
    }

    ~BusList() {
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

    // Добавление автобуса в конец списка
    void add(Bus b) {
        Node* pv = new Node;
        pv->data = b;
        pv->next = nullptr;

        if (!head) {
            head = tail = pv;
        }
        else {
            tail->next = pv;
            tail = pv;
        }
    }

    // Удаление автобуса по номеру и возврат найденного автобуса
    bool removeByNumber(int number, Bus& result) {
        Node* pv = head;
        Node* prev = nullptr;

        while (pv) {
            if (pv->data.number == number) {
                result = pv->data;

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

    // Вывод всего списка
    void print(const string& title) {
        cout << "\n" << title << endl;

        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* pv = head;
        while (pv) {
            cout << "Bus number: " << pv->data.number
                 << ", Driver: " << pv->data.driver
                 << ", Route: " << pv->data.route << endl;
            pv = pv->next;
        }
    }
};

int main() {
    BusList park;   // автобусы в парке
    BusList route;  // автобусы на маршруте

    // Начальное заполнение списка автобусов в парке
    park.add({101, "Ivanov I.I.", 12});
    park.add({102, "Petrov P.P.", 15});
    park.add({103, "Sidorov S.S.", 7});

    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1 - Show buses in park" << endl;
        cout << "2 - Show buses on route" << endl;
        cout << "3 - Send bus to route" << endl;
        cout << "4 - Return bus to park" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            park.print("Buses in park:");
        }
        else if (choice == 2) {
            route.print("Buses on route:");
        }
        else if (choice == 3) {
            int number;
            cout << "Enter bus number to send to route: ";
            cin >> number;

            Bus temp;
            if (park.removeByNumber(number, temp)) {
                route.add(temp);
                cout << "Bus moved to route" << endl;
            }
            else {
                cout << "Bus not found in park" << endl;
            }
        }
        else if (choice == 4) {
            int number;
            cout << "Enter bus number to return to park: ";
            cin >> number;

            Bus temp;
            if (route.removeByNumber(number, temp)) {
                park.add(temp);
                cout << "Bus returned to park" << endl;
            }
            else {
                cout << "Bus not found on route" << endl;
            }
        }

    } while (choice != 0);

    return 0;
}

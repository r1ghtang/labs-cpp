#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("test.txt");

    if (!fin.is_open()) {
        cout << "File not opened" << endl;
        return 0;
    }

    char ch;

    // Читаем файл до конца
    while (fin.get(ch)) {
        cout << ch;
    }

    cout << "\n\nAfter reading:" << endl;

    // Проверяем состояние потока
    cout << "eof()  = " << fin.eof() << endl;
    cout << "fail() = " << fin.fail() << endl;
    cout << "bad()  = " << fin.bad() << endl;
    cout << "good() = " << fin.good() << endl;

    // Сбрасываем состояние потока
    fin.clear();

    cout << "\nAfter clear():" << endl;
    cout << "eof()  = " << fin.eof() << endl;
    cout << "fail() = " << fin.fail() << endl;
    cout << "bad()  = " << fin.bad() << endl;
    cout << "good() = " << fin.good() << endl;

    fin.close();

    return 0;
}

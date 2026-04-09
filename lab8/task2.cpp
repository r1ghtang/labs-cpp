#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("test.txt");
    fout << "Hello file stream!" << endl;
    fout << "Second line" << endl;
    fout.close();

    ifstream fin("test.txt");

    // Проверяем, открыт ли файл
    if (!fin.is_open()) {
        cout << "File not opened" << endl;
        return 0;
    }

    char ch;

    // Читаем первый символ
    fin.get(ch);
    cout << "First symbol: " << ch << endl;

    // Возвращаем указатель чтения в начало файла
    fin.seekg(0, ios::beg);

    // Читаем первую строку
    char line[100];
    fin.getline(line, 100);
    cout << "First line: " << line << endl;

    // Показываем текущую позицию
    cout << "Current position: " << fin.tellg() << endl;

    fin.close();

    return 0;
}

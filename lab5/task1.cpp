#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char name[100];
    FILE* in;
    char ch;

    // Просим ввести имя файла
    cout << "Enter file name: ";
    cin >> name;

    // Открываем файл для чтения
    in = fopen(name, "r");

    // Проверяем, открылся ли файл
    if (in == NULL) {
        cout << "File is not opened" << endl;
        return 0;
    }

    // Читаем файл посимвольно и выводим на экран
    while ((ch = fgetc(in)) != EOF) {
        putchar(ch);
    }

    // Закрываем файл
    fclose(in);

    return 0;
}

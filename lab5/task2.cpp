#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char name[100];
    FILE* in;
    char ch;

    int emptyCount = 0;     // пробелы, табы, переводы строки
    int nonEmptyCount = 0;  // все остальные символы

    cout << "Enter file name: ";
    cin >> name;

    in = fopen(name, "r");
    if (in == NULL) {
        cout << "File is not opened" << endl;
        return 0;
    }

    // Читаем файл посимвольно
    while ((ch = fgetc(in)) != EOF) {

        // Считаем пустые символы
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            emptyCount++;
        }
        else {
            nonEmptyCount++;
        }
    }

    fclose(in);

    cout << "Empty symbols = " << emptyCount << endl;
    cout << "Non-empty symbols = " << nonEmptyCount << endl;

    return 0;
}

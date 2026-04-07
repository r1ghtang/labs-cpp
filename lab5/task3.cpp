#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char inputFile[100];
    char outputFile[100];
    char sub[100];
    char line[256];

    FILE* in;
    FILE* out;

    // Вводим имена файлов и искомую подстроку
    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    cout << "Enter substring: ";
    cin >> sub;

    in = fopen(inputFile, "r");
    if (in == NULL) {
        cout << "Input file is not opened" << endl;
        return 0;
    }

    out = fopen(outputFile, "w");
    if (out == NULL) {
        cout << "Output file is not opened" << endl;
        fclose(in);
        return 0;
    }

    // Читаем файл построчно
    while (fgets(line, 256, in) != NULL) {

        // Если подстрока найдена, записываем строку в выходной файл
        if (strstr(line, sub) != NULL) {
            fputs(line, out);
        }
    }

    fclose(in);
    fclose(out);

    cout << "Search finished" << endl;

    return 0;
}

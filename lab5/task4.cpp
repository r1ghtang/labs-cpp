#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char inputFile[100];
    char outputFile[100];
    FILE* in;
    FILE* out;
    char ch;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

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

    // Читаем посимвольно
    while ((ch = fgetc(in)) != EOF) {

        // Убираем дефисы в номерах страниц
        if (ch == '-') {
            continue;
        }

        // Символ перехода на новую страницу сохраняем
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    cout << "File processed" << endl;

    return 0;
}

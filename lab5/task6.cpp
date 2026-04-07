#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {

    // Проверяем количество аргументов
    if (argc < 4) {
        cout << "Usage: program input.txt output.txt key" << endl;
        return 0;
    }

    FILE* in;
    FILE* out;
    char ch;
    int i = 0;
    int keyLen = strlen(argv[3]);

    // argv[1] - входной файл
    // argv[2] - выходной файл
    // argv[3] - ключ
    in = fopen(argv[1], "rb");
    if (in == NULL) {
        cout << "Input file is not opened" << endl;
        return 0;
    }

    out = fopen(argv[2], "wb");
    if (out == NULL) {
        cout << "Output file is not opened" << endl;
        fclose(in);
        return 0;
    }

    // Шифруем файл
    while ((ch = fgetc(in)) != EOF) {
        char encrypted = ch ^ argv[3][i];
        fputc(encrypted, out);

        i++;
        if (i == keyLen) i = 0;
    }

    fclose(in);
    fclose(out);

    cout << "File processed" << endl;

    return 0;
}

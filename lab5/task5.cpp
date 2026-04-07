#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char inputFile[100];
    char outputFile[100];
    char key[100];

    FILE* in;
    FILE* out;
    char ch;
    int i = 0;
    int keyLen;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    cout << "Enter key: ";
    cin >> key;

    keyLen = strlen(key);

    in = fopen(inputFile, "rb");
    if (in == NULL) {
        cout << "Input file is not opened" << endl;
        return 0;
    }

    out = fopen(outputFile, "wb");
    if (out == NULL) {
        cout << "Output file is not opened" << endl;
        fclose(in);
        return 0;
    }

    // Читаем файл посимвольно и шифруем
    while ((ch = fgetc(in)) != EOF) {
        char encrypted = ch ^ key[i];
        fputc(encrypted, out);

        // Переходим к следующему символу ключа циклически
        i++;
        if (i == keyLen) i = 0;
    }

    fclose(in);
    fclose(out);

    cout << "File encrypted" << endl;

    return 0;
}

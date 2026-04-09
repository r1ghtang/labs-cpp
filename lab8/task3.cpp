#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char inputFile[100];
    char outputFile[100];
    char key[100];

    cout << "Enter input file: ";
    cin >> inputFile;

    cout << "Enter output file: ";
    cin >> outputFile;

    cout << "Enter key: ";
    cin >> key;

    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);

    if (!fin.is_open()) {
        cout << "Input file not opened" << endl;
        return 0;
    }

    if (!fout.is_open()) {
        cout << "Output file not opened" << endl;
        return 0;
    }

    int keyLen = strlen(key);
    int i = 0;
    char ch;

    // Читаем файл посимвольно и шифруем
    while (fin.get(ch)) {
        char encrypted = ch ^ key[i];
        fout.put(encrypted);

        i++;
        if (i == keyLen) i = 0;
    }

    fin.close();
    fout.close();

    cout << "File processed" << endl;

    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // calloc сразу заполняет память нулями
    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));

    cout << "Enter str1: ";
    cin >> str1;

    cout << "Enter str2: ";
    cin >> str2;

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    free(str1);
    free(str2);

    return 0;
}

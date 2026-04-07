#include <iostream>
using namespace std;

int main() {
    const int N = 3;
    char str[N][100];

    // ввод строк
    for (int i = 0; i < N; i++) {
        cout << "Enter string " << i << ": ";
        cin >> str[i];
    }

    // вывод строк
    cout << "\nStrings:\n";
    for (int i = 0; i < N; i++) {
        cout << str[i] << endl;
    }

    return 0;
}

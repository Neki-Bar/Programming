
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Форма ввода:\nОснование степени\nПоказатель степени\n";
    int i = 1;
    int osn, poc;
    while (i) {
        cin >> osn;
        cin >> poc;
        int st = 1;
        for (int j = 0; j < poc; j++) {
            st *= osn;
        }
        cout << osn << "^" << poc << "=" << st;
        cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
        cin >> i;
    }

}


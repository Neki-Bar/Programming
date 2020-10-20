
#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    cout << "Введите число для подсчета включенных в него степеней двойки (0<=n<=10^15, n = [N])\n";
    long long n;
    int i = 1;
    while(i) {
        cin >> n;
        int count = 0;
        if (n >= 0 && n <=100000000000000) {
            for (long long int i = 1; i <= n; i*=2) {
                count++;
            }
            cout << "Количество степеней двойки = " << count << "\n";
        }
        else cout << "Неправильный ввод";
        cout << "Для продолжения введите 1\nДля выхода введите 0\n";
        cin >> i;
    }
    
}



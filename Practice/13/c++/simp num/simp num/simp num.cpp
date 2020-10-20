
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	cout << "Введите чимло чтобы узнать является ли оно простым (2<=n<=10^9)\n";
	int n;
	int i = 1;
	while (i) {
		cin >> n;
		if (2 <= n && n <= 1000000000) {
			if ((n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0) || n == 2 || n == 3 || n == 5 || n == 7)
				cout << "Число " << n << " простое";
			else
				cout << "Число " << n << " составное";
		}else cout << "Неправильный ввод";
		
		cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> i;
	}
}



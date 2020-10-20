

#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	cout << "Введите число для вычисления факториала(1<=n<=12)\n";
	int j = 1;
	while (j) {
		int n;
		cin >> n;
		int fact = 1;
		if (1 <= n && n <= 12) {
			for (int i = 1; i < n + 1; i++) {
				fact *= i;
			}
			cout << n << "! = " << fact;
		}
		else
			cout << ("Неправильный ввод");
		cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> j;
	}
}



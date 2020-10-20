
#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int h1, m1, h2, m2;
	int i = 1;
	cout << "Формат ввода:\nВремя прихода 1-го человека чч:мм\nВремя прихода 2-го человека чч:мм\n";
	while (i) {
		cin >> h1;
		cin.ignore(1);
		cin >> m1;
		cin >> h2;
		cin.ignore(1);
		cin >> m2;
		if (h1 <= 23 && h1 >= 0 && h2 <= 23 && h2 >= 0 && m1 < 60 && m1 >= 0 && m2 < 60 && m2 >= 0) {
			if (abs((h1 * 60 + m1) - (h2 * 60 + m2)) > 15)
				cout << "Встреча не состоится\n";
			else
				cout << "Встреча состоится\n";
		}
		cout << "Для продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> i;
	}
}


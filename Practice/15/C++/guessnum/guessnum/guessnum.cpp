
#include <iostream>
#include <ctime>

using namespace std;

int main() {

	setlocale (LC_ALL, "rus");
	int i = 1;
	int randnum;
	int usernum;
	int j;
	cout << "Компьютер загадал случайное целое число  в диапазоне 0<=n<=100. Вам даётся 5 попыток угадать это число.\n";
	while (i) {
		srand(time(0));
		randnum = rand() % 101;
		for (j = 0; j < 5; j++) {
			cin >> usernum;
			if (0 <= usernum && usernum <= 100) {
				if (usernum == randnum || j != 4) {
					if (usernum < randnum) cout << "Загаданное число больше\n";
					if (usernum > randnum) cout << "Загаданное число меньше\n";
				}
				if (usernum == randnum) {
					cout << "Поздравляю! Вы угадали\n";
					break;
				}
			}
			else cout << "Неправильный ввод\n";
		}
		if (j == 5) {
			cout << "Вы проиграли. Было загадано: {" << randnum << "}\n";
		}
		cout << "Хотите начать сначала? (1 - ДА )\n";
		cin >> i;
		if (i != 1) i = 0;
	}
}



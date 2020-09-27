
#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	cout << "Калькулятор\nФормат ввода:\nЧерез пробел: 1-й операнд, оператор(+-*/), 2-й операнд\n";
	double a, b;
	char oper;
	int i = 1;
	while (i) {
		cin >> a >> oper >> b;
		if (oper == '+') cout << a + b;
		if (oper == '-') cout << a - b;
		if (oper == '*') cout << a * b;
		if (oper == '/') cout << a / b;
		if (oper != '+' && oper != '-' && oper != '*' && oper != '/') cout << "Вы не правильно ввели оператор";
		cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> i;
	}
}


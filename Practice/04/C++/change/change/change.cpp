
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "С помощью переменной\n";
	int a, b;
	cout << "Введите число a\n";
	cin >> a;
	cout << "Введите число b\n";
	cin >> b;
	int c = a;
	a = b;
	b = c;
	cout << "a = " << a << " b = " << b;

	cout << "\nБез помощи переменной\n";
	int d;
	cout << "Введите число c\n";
	cin >> c;
	cout << "Введите число d\n";
	cin >> d;
	d = c * d;
	c = d / c;
	d = d / c;
	cout << "c = " << c << " d = " << d;

}

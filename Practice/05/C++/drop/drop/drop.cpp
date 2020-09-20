
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите начальную координату (м)\n";
	double x;
	cin >> x;
	cout << "Введите начальную скорость (м/с)\n";
	double v;
	cin >> v;
	cout << "Введите время падения (с)\n";
	double t;
	cin >> t;
	cout << "Пройденное расстояние: " << (x + v * t + 9.8 * t * t / 2) - x ;

}



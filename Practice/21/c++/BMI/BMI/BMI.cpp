#include <iostream>

using namespace std;

double BMI(double weight, double height) {
	return weight / height / height;
}

void printBMI(double BMI) {
	if(BMI < 18.5)  cout << "Underweight";
	if (18.5 <= BMI && BMI< 25.0)  cout << "Normal weight";
	if (25.0 <= BMI && BMI < 30.0)  cout << "Overweight";
	if (30.0 <= BMI)  cout << "Obesity";
}

int main() {
	setlocale(LC_ALL, "rus");
	double weight, height;
	cout << "Введите свой вес в килограммах и рост в метрах.(через пробел)\n";
	cin >> weight >> height;
	printBMI(BMI(weight, height));
}


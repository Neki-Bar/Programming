
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a, b;
    cout << "Введите числа";
    cin >> a >> b;
    cout << "int/int\n" << a + b << " " << a - b << " " << a / b << " " <<  a * b << "\n";
    double c = a, d = b;
    cout << "double/double\n" << c + b << " " << c - b << " " << c / d << " " << c * d << "\n";
    int e = a;
    double f = b;
    cout << "int/double\n" << e + f << " " << e - f << " " << e / f << " " << e * f << "\n";
    double g = a;
    int h = b;
    cout << "double/int\n" << g + h << " " << g - h << " " << g / h<< " " << g * h << "\n";
    system("pause");
    return 0;
}



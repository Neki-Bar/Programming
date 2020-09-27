#include <cmath>
#include <iostream>

using namespace std;
void area(double x, double y, double z) {
    if (x + y > z and x + z > y and y + z > x) {
        double p = (x + y + z) / 2;
        cout << "S = " << sqrt(p * (p - x) * (p - y) * (p - z)) << "\n";
    }
    else
        cout << "Такой треугольник не существует\n";
    
}

int main(){
    setlocale(LC_ALL, "rus");
    int i = 1;
    while (i) {
        cout << "Выберите способ ввода:\n1 - через дины сторон;\n2 - через координаты вершин\n";
        int choose;
        cin >> choose;
        if (choose == 1) {
            cout << "Введите длину стороны a ";
            double a;
            cin >> a;
            cout << "Введите длину стороны b ";
            double b;
            cin >> b;
            cout << "Введите длину стороны c ";
            double c;
            cin >> c;
            area(a, b, c);
        }
        else{
            if (choose == 2) {
                cout << "Введите координаты вершины A через пробел ";
                double ax, ay;
                cin >> ax >> ay;
                cout << "Введите координаты вершины B через пробел ";
                double bx, by;
                cin >> bx >> by;
                cout << "Введите координаты вершины C через пробел ";
                double cx, cy;
                cin >> cx >> cy;
                double a = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
                double b = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));
                double c = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
                area(a, b, c);
            }
            else cout << "Вы неправильно указали способ ввода";
        }
        cout << "Для продолжения введите 1\nЧтобы выйти введите 0\n";
        cin >> i;
    }
    
}



#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	long long int s, l1, r1, l2, r2;
	int i = 1;
	while (i) {
		cout << "Введите через пробел значения s, l1, r1, l2, r2\n";
		cin >> s >> l1 >> r1 >> l2 >> r2;
		if ((s >= l1 + l2) && (s <= r1 + r2)) {
			if (l1 + r2 - s == 0) cout << "x1 = " << l1 << " x2 = " << r2;
			if (l1 + r2 - s < 0) cout << "x1 = " << l1 - (l1 + r2 - s) << " x2 = " << r2;
			if (l1 + r2 - s > 0) cout << "x1 = " << l1 << " x2 = " << r2 - (l1 + r2 - s);
		}
		else {
			cout << -1;
		}
		cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> i;
	}
}


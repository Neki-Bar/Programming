#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int i = 1;
	int max = 0;
	int red = 0;
	int black = 0;
	int nom;
	int noms[37];
	for (int i = 0; i < 37; i++) {
		noms[i] = 0;
	}
	int ends[37];
	for (int i = 0; i < 37; i++) {
		ends[i] = 0;
	}
	int count = 0;
	while (i) {
		cout << "Введите последний результат\n";
		cin >> nom;
		if (nom == -1) break;
		if (nom >= 0 && nom < 37) {
			noms[nom]++;
			ends[nom] = 1 + count%12;
			if (nom % 2 == 0 && nom != 0) black++;
			if (nom % 2 == 1 && nom != 0) red++;
			for (int i = 0; i < 37; i++) {
				if (noms[i] > max) max = noms[i];
			}
			cout << "Выпадали чаще всего: ";
			for (int i = 0; i < 37; i++) {
				if (noms[i] == max) cout << i << " ";
			}
			cout << "\nНе выпадали за последние 12 игр: ";
			for (int i = 0; i < 37; i++) {
				if(ends[i] == 0) cout << i << " ";
				if (ends[i] != 0 && i != nom && count > 10) ends[i]--;
			}
			cout << "\nКрасное/черное ";
			cout << red << " " << black << "\n";
			count++;
		}
	}
}


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
	int ends[12];
	for (int i = 0; i < 12; i++) {
		ends[i] = 0;
	}
	int count = 0;
	while (i) {
		cout << "Введите последний результат\n";
		cin >> nom;
		if (nom > 0 && nom < 37) {
			noms[nom]++;
			ends[count%12] = nom;
			if (nom % 2 == 0) black++;
			if (nom % 2 == 1) red++;
		}
		for (int i = 0; i < 37; i++) {
			if (noms[i] > max) max = noms[i];
		}
		cout << "\nВыпадали чаще всего: ";
		for (int i = 0; i < 37; i++) {
			if (noms[i] == max) cout << i << " ";
		}
		cout << "\nВыпадали за последние 12 игр: ";
		for (int i = 0; i < 12; i++) {
			if(ends[i] != 0) cout << ends[i] << " ";
		}
		cout << "\nКрасное/черное ";
		cout << red << " " << black << "\n";
		count++;
	}
}


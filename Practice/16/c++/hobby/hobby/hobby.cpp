
#include <iostream>
#include <vector>

using namespace std;


int main(){
	setlocale(LC_ALL, "rus" );
	int i = 1;
	int n;
	vector <string> out;
	string bilet;
	cout << "В первой строке введите количество билетов а во второй все номера билетов.\n";
	while (i) {
		out = {};
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> bilet;
			if (bilet[0] == 'a' && bilet[4] == '5' && bilet[5] == '5' && bilet[6] == '6' && bilet[7] == '6' && bilet[8] == '1') {
				out.push_back(bilet);
			}
		}
		cout << "Билеты Суслика:";
		for (int i = 0; i < out.size(); i++) {
			cout << out.at(i) << " ";
		}
		cout << "\nДля продолжения введите 1\nЧтобы выйти введите 0\n";
		cin >> i;
	}
	
}
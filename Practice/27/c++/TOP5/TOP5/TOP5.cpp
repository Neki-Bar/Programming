#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int indOfMax (vector <int> vec) {
	int ind = 0;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > vec[ind]) ind = i;
	}
	return ind;
}

bool comp(int a, int b) {
	return a > b;
}

int main(){
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество сигналов.\n";
	cin >> n;
	cout << "Введите сигналы через пробел.\n";
	if (n >= 1 && n <= 100000) {
		int a;
		vector <int> top = {1000001,1000001,1000001,1000001,1000001};
		vector<vector<int>> list;
		int maxind = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a >= -1000000 && a <= 1000000) {
				maxind = indOfMax(top);
				if (a < top[maxind]) {
					top[maxind] = a;
					sort(top.begin(), top.end(), comp );
					list.push_back(top);
				}
				else {
					list.push_back(top);
				}
			}
			
		}
		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list[i].size(); j++) {
				if (list[i][j] >= -1000000 && list[i][j] <= 1000000) {
					cout << list[i][j] << " ";
				}
			}
			cout << "\n";
		}
	}
	
}


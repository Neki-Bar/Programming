
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

vector <int> BozoSort(vector <int> vec, bool comp = true) {
	srand(time(0));
	bool check = true;
	int first, second;
	int temp;
	while (check) {
		check = false;
		for (int i = 0; !check && i < vec.size() - 1; i++) {
			if (comp) {
				if (vec[i] > vec[i+1]) check = true;
				if (check) break;
			}
			else {
				if (vec[i] < vec[i+1]) check = true;
				if (check) break;
			}
		}
		if (check) {
		int first = rand() % vec.size();
		int second = rand() % vec.size();
		temp = vec[first];
		vec[first] = vec[second];
		vec[second] = temp;
		}
		
	}
	
	return vec;
}

vector <int> BozoSort(vector <vector <int>> vec, bool comp = true) {
	srand(time(0));
	vector <int> tempVec;
	for (int i = 0; i < sqrt(vec.size()); i++) {
		for (int j = 0; j < sqrt(vec.size()); j++) {
			tempVec.push_back(vec[i][j]);
		}
	}
	bool check = true;
	int first, second;
	int temp;
	while (check) {
		check = false;
		for (int i = 0; !check && i < tempVec.size() - 1; i++) {
			if (comp) {
				if (tempVec[i] > tempVec[i + 1]) check = true;
				if (check) break;
			}
			else {
				if (tempVec[i] < tempVec[i + 1]) check = true;
				if (check) break;
			}
		}
		if (check) {
			int first = rand() % tempVec.size();
			int second = rand() % tempVec.size();
			temp = tempVec[first];
			tempVec[first] = tempVec[second];
			tempVec[second] = temp;
		}
	}
	
	return tempVec;
}

vector <int> BozoSort(int a, int b, int c, bool comp = true) {
	srand(time(0));
	vector <int> tempVec;
	tempVec.push_back(a);
	tempVec.push_back(b);
	tempVec.push_back(c);
	bool check = true;
	int first, second;
	int temp;
	while (check) {
		check = false;
		for (int i = 0; !check && i < tempVec.size() - 1; i++) {
			if (comp) {
				if (tempVec[i] > tempVec[i + 1]) check = true;
				if (check) break;
			}
			else {
				if (tempVec[i] < tempVec[i + 1]) check = true;
				if (check) break;
			}
		}
		if (check) {
			int first = rand() % tempVec.size();
			int second = rand() % tempVec.size();
			temp = tempVec[first];
			tempVec[first] = tempVec[second];
			tempVec[second] = temp;
		}
	}
	
	return tempVec;

}

int main(){
	setlocale(LC_ALL, "rus");
	int amount;
	cout << "В первой строке введите кольчество чисел, а во второй - сами числа.\n";
	while (1) {
		cin >> amount;
		if (sqrt(amount) != floor(sqrt(amount)) || amount > 100) {
			cout << "Неправильный ввод.";
		}
		else break;
	}
	vector <int> array;
	vector <vector <int>> vectorOfVectors(sqrt(amount));
	int temp;
	for (int i = 0; i < sqrt(amount); i++) {
		for (int j = 0; j < sqrt(amount); j++) {
			cin >> temp;
			array.push_back(temp);
			vectorOfVectors[i].push_back(temp);
		}
	}
	auto a = BozoSort(array);
	for (int i = 0; i < amount; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	auto b = BozoSort(array, false);
	for (int i = 0; i < amount; i++) {
		cout << b[i] << " ";
	}
	cout << "\n";

	auto c = BozoSort(vectorOfVectors);
	for (int i = 0; i < amount; i++) {
		cout << c[i] << " ";
	}
	cout << "\n";

	auto d = BozoSort(vectorOfVectors, false);
	for (int i = 0; i < amount; i++) {
		cout << d[i] << " ";
	}
	cout << "\n";

	auto e = BozoSort(array[0], array[1], array[2]);
	for (int i = 0; i < 3; i++) {
		cout << e[i] << " ";
	}
	cout << "\n";

	auto f = BozoSort(array[0], array[1], array[2], false);
	for (int i = 0; i < 3; i++) {
		cout << f[i] << " ";
	}
}




#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

template<typename T>
vector <T> BozoSort(vector <T> vec, bool comp = true) {
	srand(time(0));
	bool check = true;
	int first, second;
	T temp;
	while (check) {
		check = false;
		for (int i = 0; !check && i < vec.size() - 1; i++) {
			if (comp) {
				if (vec[i] > vec[i + 1]) check = true;
				if (check) break;
			}
			else {
				if (vec[i] < vec[i + 1]) check = true;
				if (check) break;
			}
		}
		if (check) {
			first = rand() % vec.size();
			second = rand() % vec.size();
			temp = vec[first];
			vec[first] = vec[second];
			vec[second] = temp;
		}

	}

	return vec;
}

template <typename T >
 vector <T> BozoSort(vector <vector <T>> vec, bool comp = true) {
	srand(time(0));
	vector <T> tempVec;
	for (int i = 0; i < sqrt(vec.size()); i++) {
		for (int j = 0; j < sqrt(vec.size()); j++) {
			tempVec.push_back(vec[i][j]);
		}
	}
	bool check = true;
	int first, second;
	T temp;
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
			first = rand() % tempVec.size();
			second = rand() % tempVec.size();
			temp = tempVec[first];
			tempVec[first] = tempVec[second];
			tempVec[second] = temp;
		}
	}

	return tempVec;
}

template <typename T>
vector <T> BozoSort(T a, T b, T c, bool comp = true) {
	srand(time(0));
	vector <T> tempVec;
	tempVec.push_back(a);
	tempVec.push_back(b);
	tempVec.push_back(c);
	bool check = true;
	int first, second;
	T temp;
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
			first = rand() % tempVec.size();
			second = rand() % tempVec.size();
			temp = tempVec[first];
			tempVec[first] = tempVec[second];
			tempVec[second] = temp;
		}
	}

	return tempVec;

}

template <typename T, typename T1>
void printRes(T array, T1 vectorOfVectors, int amount) {
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
	cout << "\n";
}

int main() {
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
	vector <double> array;
	vector <vector <double>> vectorOfVectors(sqrt(amount));
	double temp;
	for (int i = 0; i < sqrt(amount); i++) {
		for (int j = 0; j < sqrt(amount); j++) {
			cin >> temp;
			array.push_back(temp);
			vectorOfVectors[i].push_back(temp);
		}
	}
	printRes(array, vectorOfVectors, amount);


	while (1) {
		cin >> amount;
		if (sqrt(amount) != floor(sqrt(amount)) || amount > 100) {
			cout << "Неправильный ввод.";
		}
		else break;
	}
	vector < string > s;
	vector <vector < string > > smatrix(sqrt(amount));
	string temp1;
	for (int i = 0; i < sqrt(amount); i++) {
		for (int j = 0; j < sqrt(amount); j++) {
			cin >> temp1;

			s.push_back(temp1);
			smatrix[i].push_back(temp1);
		}
	}
	printRes(s, s, amount);
	
	
}



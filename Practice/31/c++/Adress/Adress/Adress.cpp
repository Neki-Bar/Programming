#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ostream& operator<<(ostream& os, vector<int> const vec) {
	os << vec.size() << "\t| ";
	for (int i = 0; i < vec.size(); i++) {
		os << &vec[i] << " ";
	}
	os << "\n";
	return os;
}

int main(){
	setlocale(LC_ALL, "rus");
	ofstream file;
	file.open("data.txt");
	if (file.is_open()) {
		cout << "Файл открыт.\n";
		vector<int> adress;
		for (int i = 0; i < 64; i++) {
			adress.push_back(1);
			file << adress;
		}
		while (adress.size()) {
			adress.pop_back();
			file << adress;
		}
	}
	else {
		cout << "Ошибка при открывании файла.\n";
	}
	file.close();


}


/*
1. В большенчтве случаев ячейка, следующая за последней, занята другими данными поэтому вектор создает массив длиннее на один элемент,
переносит в него данные и меняет адрес первой ячейки на новый.
2. Так как после увеличения вектора адрес меняется то обращение по старому адресу не изменит первый элемент нового вектора.
3. В случве удаления элементов не возникает проблемы нехватки места, поэтому с конца вектора просто удаляется элемент, а адрес первой ячейки остается прежним.
4. При передаче вектора по значению ничего не меняется, так как логика фдресов от этого не меняется.
*/

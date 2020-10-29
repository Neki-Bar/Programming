
#include <iostream>
#include <map>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	string know = "halloklempnerdasistfantastischfluggegecheimen";
	map <char, double> prob;
	double probability = 1;
	int size = know.size();
	string stop;
	for (int i = 0; i < size; i++) {
		prob[know[i]]++;
	}
	
	
	cout << "Введите стоп-слово\n";
	cin >> stop;
	map <char, double> ::iterator it = prob.begin();
	for (int i = 0; i < stop.size(); i++) {
		it = prob.find(stop[i]);
		if (it->first == stop[i]) {
			probability *= it->second/size;
		}
		else {
			probability = 0;
			break;
		}
	}
	cout << probability;
	
}


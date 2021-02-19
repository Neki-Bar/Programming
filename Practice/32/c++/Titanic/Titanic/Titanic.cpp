#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

struct Passenger {
private:
	map<string, string> person;
public:
	Passenger(map<string, string> person);


};

Passenger::Passenger(map<string, string> person) {
	this->person = person;
}

istream& operator>>(istream& is, vector<Passenger>& vec) {
	ifstream data;
	data.open("train.csv");
	string str;
	data.ignore(256, '\r');
	map<string, string> person = { {"PassengerId", ""}, {"Survived", ""}, {"Pclass", ""},
		{"Name", ""}, {"Sex", ""}, {"Age", ""}, {"SibSp", ""}, {"Parch", ""}, {"Ticket", ""},
		{"Fare", ""}, {"Cabin", ""}, {"Embarked", ""} };
	for (int i = 0;true;i++) {
		if (i > 12 && i % 12 == 0) vec.push_back(Passenger(person));
		if (i > 11 && !data.eof()) {
			switch (i % 12) {
			case(0):
				getline(data, str, ',');
				person["PassengerId"] = str;
				break;
			case(1):
				getline(data, str, ',');
				person["Survived"] = str;
				break;
			case(2):
				getline(data, str, ',');
				person["Pclass"] = str;
				break;
			case(3):
				getline(data, str, ',');
				person["Name"] = str;
				getline(data, str, ',');
				person["Name"] += str;
				break;
			case(4):
				getline(data, str, ',');
				person["Sex"] = str;
				break;
			case(5):
				getline(data, str, ',');
				person["Age"] = str;
				break;
			case(6):
				getline(data, str, ',');
				person["SibSp"] = str;
				break;
			case(7):
				getline(data, str, ',');
				person["Parch"] = str;
				break;
			case(8):
				getline(data, str, ',');
				person["Ticket"] = str;
				break;
			case(9):
				getline(data, str, ',');
				person["Fare"] = str;
				break;
			case(10):
				getline(data, str, ',');
				person["Cabin"] = str;
				break;
			case(11):
				getline(data, str, '\r');
				person["Embarked"] = str;
				break;
			};
		}
		else {
			break;
		}
	}
	return is;
}

ostream& operator<<(ostream& os, vector<Passenger>& vec) {

	return os;
}

string eraseBrackets(string& str) {
	string newstr = str;
	str.erase(0, 1);
	str.erase(string::npos - 1, 1);
	size_t ind;
	for (size_t i = 0; i < str.size(); i++) {
		if (ind > 0) {

		}
	}

	return newstr;
}

int main()
{
	
	
}


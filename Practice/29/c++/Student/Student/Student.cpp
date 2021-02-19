#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;



struct Student
{
private:
	string name;
	int group;
	map <string, int> exams;

	
public:
	Student() {
		this->name = "";
		this->group = 0;
		this->exams = { { "mathematics" , 0}, { "physics" , 0}, { "history" , 0}, { "programming" , 0} };
	}

	Student(string name, int group, map <string, int>& exams){
		this->name = name;
		if (group >= 1 && group <= 9) this->group = group;
		map <string, int>::iterator itr;
		bool check = false;
		for (itr = exams.begin(); itr != exams.end(); itr++) {
			if ((itr->first == "mathematics" || itr->first == "physics" || itr->first == "history" || itr->first == "programming") &&
				(itr->second >= 2 && itr->second <= 5))
			{
				check = true;
			}
			else {
				check = false;
			}
		}
		if (check) this->exams = exams;
	}

	map <string, int> getExams();

	friend void printStudent(ostream& os, const Student& st);
	friend bool operator>(Student a, Student b);
	friend bool operator<(Student a, Student b);
};

ostream& operator<<(ostream& os, const Student& st);
ostream& operator<<(ostream& os, const vector<Student>& vec);
void printStudent(ostream& os, const Student& st);
void printHeader(ostream& os);
string space(string obj, int n);
string space(int obj, int n);
void printLine(ostream& os);
template<typename T>
vector <T> BozoSort(vector <T> vec, bool comp = true);

ostream& operator<<(ostream& os, const Student& st) {
	printHeader(os);
	printStudent(os, st);
	return os;
}

ostream& operator<<(ostream& os, const vector<Student>& vec) {
	printHeader(os);
	for (int i = 0; i < vec.size(); i++) {
		printStudent(os, vec[i]);
	}
	return os;
}

bool operator>(Student a, Student b) {
	return a.name > b.name;
}

bool operator<(Student a, Student b) {
	return a.name < b.name;
}

map<string, int> Student::getExams()
{
	return exams;
}

void printStudent(std::ostream& os, const Student& st) {
	map <string, int> exams = st.exams;
	os << "| " << st.name << space(st.name, 21) << "|";
	os << " " << st.group << space(st.group, 6) << "|";
	os << " " << exams["mathematics"] << space(exams["mathematics"], 5) << "|";
	os << " " << exams["physics"] << space(exams["physics"], 5) << "|";
	os << " " << exams["history"] << space(exams["history"], 5) << "|";
	os << " " << exams["programming"] << space(exams["programming"], 5) << "|\n";
	printLine(os);
}


void printHeader(ostream& os) {
	os << "+----------------------+-------+------+------+------+------+\n";
	os << "| Name                 | Group | Math | Phys | Hist | Prog |\n";
	os << "+----------------------+-------+------+------+------+------+\n";
}

string space(string obj, int n) {
	string sp = "";
	for (int i = 0; i < n - obj.size(); i++) {
		sp += " ";
	}
	return sp;
}

string space(int obj, int n) {
	string str = to_string(obj);
	string sp = "";
	for (int i = 0; i < n - str.size(); i++) {
		sp += " ";
	}
	return sp;
}

void printLine(ostream& os) {
	os << "+----------------------+-------+------+------+------+------+\n";
}

template<typename T>
vector <T> BozoSort(vector <T> vec, bool comp) {
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

int main(){
	vector <Student> jur;
	string names[] = { "Ivanov Y" , "Sidorov I", "Popov V", "Lebedev V", "Shihman A", "Musaev A", "Ushaev K", "Bondar D", "Khaev N", "Levin I" };
	int ran;
	srand(time(0));
	map <string, int> exams = { { "mathematics" , 0}, { "physics" , 0}, { "history" , 0}, { "programming" , 0} };
	map <string, int>::iterator itr;
	for (int i = 0; i < 10; i++) {
		for (itr = exams.begin(); itr != exams.end(); itr++) {
			ran = rand() % 4 + 2;
			itr->second = ran;
		}
		ran = rand() % 9 + 1;
		
		jur.push_back(Student(names[i], ran, exams));
	}

	
	vector<Student> haveTwo;
	for (int i = 0; i < 10; i++) {
		exams = jur[i].getExams();
		for (itr = exams.begin(); itr != exams.end(); itr++) {
			if (itr->second == 2) {
				haveTwo.push_back(jur[i]);
				break;
			}
		}
	}
	if (haveTwo.size()) {
		haveTwo = BozoSort(haveTwo,true);
		cout << haveTwo << "\n";

		cout << "Expulsion" << "\n";

		cout << haveTwo[rand() % haveTwo.size()];
	}
	else {
		cout << "Not found";
	}
	
}



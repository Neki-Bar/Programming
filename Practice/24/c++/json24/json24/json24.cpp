
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <map>

#include <ctime>
using json = nlohmann::json;

int main() {
	
	std::string path = "sourse.json";
	std::ifstream file;

	file.open(path);

	json sourse;

	file >> sourse;

	json res = json::parse("[\n]");

	json obj;

	std::map<int, int> users;

	for (auto& temp : sourse.items()) {
		if (temp.value()["task"]) {
			users[temp.value()["userId"]]++;
		}
	}

	for (auto& temp : users) {
			obj = {
				{"task_completed", temp.second},
				{"userId", temp.first}
				
			};
		res.push_back(obj);
	}
	file.close();
	std::string path1 = "res.json";
	std::ofstream file1;
	file1.open(path1);
	file1 << res;
	file1.close();





}

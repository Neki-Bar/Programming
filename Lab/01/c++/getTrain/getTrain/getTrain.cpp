#include <iostream>
#include <json.hpp>
#include <typeinfo>
using json = nlohmann::json;
using namespace std;
int main() {
	string temp = R"({
"lat":44.96,
"lon":34.11,
"timezone":"Europe/Simferopol",
"timezone_offset":10800,
"hourly":[{
"dt":1605963600,
"temp":5.05,
"feels_like":1.31,
"pressure":1026,
"humidity":75,
"dew_point":0.99,
"clouds":96,
"visibility":10000,"wind_speed":2.72,"wind_deg":17,"weather":[{"id":804,"main":"Clouds","description":"пасмурно","icon":"04d"}],"pop":0.01},]})";
	json t = json::parse(temp);
	auto a = t["hourly"][0];
	cout << typeid(a["temp"].get<string>()).name();
}
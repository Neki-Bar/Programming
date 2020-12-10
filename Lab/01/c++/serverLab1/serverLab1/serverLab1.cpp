
#include <iostream>
#include <fstream>
#include <string>
#include <httplib.h>
#include <json.hpp>
#include <sstream>


using json = nlohmann::json;
using namespace httplib;

json cache = "";

template <typename T>
std::string toString(T val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

int getNumOfHour() {
    int locItem = 0;
    int sec = 0;
    if (cache == "") {
                Client cli("http://api.openweathermap.org");
                auto res = cli.Get("/data/2.5/onecall?appid=13fda1439b44a8ade1b03e584c366ec5&lat=44.9572&lon=34.1108&exclude=daily,minutely,current,alerts&lang=ru&units=metric");
                if (res) {
                    if (res->status == 200) {
                        cache = json::parse(res->body);
                    }
                    else {
                        std::cout << "1Openweathermap status code: " << res->status << std::endl;
                    }
                }
                else {
                    auto err = res.error();
                    std::cout << "1Openweathermap error code: " << err << std::endl;
                }
    }
    else {
                Client cli("http://worldtimeapi.org");
                auto res = cli.Get("/api/timezone/Europe/Simferopol");
                if (res) {
                    if (res->status == 200) {
                        sec = json::parse(res->body)["unixtime"].get<int>();
                    }
                    else {
                        std::cout << "Worldtimeapi status code: " << res->status << std::endl;
                    }
                }
                else {
                    auto err = res.error();
                    std::cout << "Worldtimeapi error code: " << err << std::endl;
                }
                int checkActual = 0;
        
        if (sec) {
            for (int i = 0; i < 48; i++) {
                if ((cache["hourly"][i]["dt"] - sec) > 0 && (cache["hourly"][i]["dt"] - sec) <= 3600) {
                    checkActual = cache["hourly"][i]["dt"];
                    locItem = i;
                    break;
                }
            }
        }
        



        if (!checkActual) {

                    Client cli("http://api.openweathermap.org");
                    auto res = cli.Get("/data/2.5/onecall?appid=13fda1439b44a8ade1b03e584c366ec5&lat=44.9572&lon=34.1108&exclude=daily,minutely,current,alerts&lang=ru&units=metric");
                    if (res) {
                        if (res->status == 200) {
                            cache = json::parse(res->body);
                        }
                        else {
                            std::cout << "Openweathermap status code: " << res->status << std::endl;
                        }
                    }
                    else {
                        auto err = res.error();
                        std::cout << "Openweathermap error code: " << err << std::endl;
                    }
        }
    }
    if (cache == "")
        locItem = -1;
    return locItem;
}

void gen_response(const Request& req, Response& res) {
    int item = getNumOfHour();
    
    std::string tempFile;

    std::string repStr[4] = { "{hourly[i].weather[0].description}","{hourly[i].weather[0].icon}","{hourly[i].temp}","{hourly[i].temp}" };
    

    std::string pathTemplate = "index.html";

    std::ifstream templateFile;
    if (item >= 0) {
        templateFile.open(pathTemplate);

        auto temp = cache["hourly"][item];

        if (!templateFile.is_open()) {
            std::cout << "Не удалось открыть файл шаблона виджета.";
        }
        else {
            
            getline(templateFile, tempFile, '\0');
       
            tempFile.replace(tempFile.find(repStr[0]), repStr[0].length(), temp["weather"][0]["description"].get<std::string>());
            tempFile.replace(tempFile.find(repStr[1]), repStr[1].length(), temp["weather"][0]["icon"].get<std::string>());
            tempFile.replace(tempFile.find(repStr[3]), repStr[3].length(), toString(temp["temp"]));



        }
    }
    
	res.set_content(tempFile , "text/html");
}

void gen_responseRaw(const Request& req, Response& res) {
    int item = getNumOfHour();
    if (item >= 0) {
        auto temp = cache["hourly"][item];
        json result = {
            {"temperature", temp["temp"].get<int>()},
            {"description", temp["weather"][0]["description"].get<std::string>()}
        };

        res.set_content(result.dump(), "text/json");
    }
}


int main() {
	Server svr;                    
	svr.Get("/", gen_response);   
	svr.Get("/raw", gen_responseRaw);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 3000); 

  
}


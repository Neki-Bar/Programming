
#include <iostream>
#include <string>
#include <httplib.h>
#include <json.hpp>

using json = nlohmann::json;

using namespace httplib;

void gen_response(const Request& req, Response& res) {
    std::cout << req.body.c_str();
    std::string str = u8R"(
    {
      "response": {
        "text": "Здравствуйте! Это мы, хороводоведы.",
        "tts": "Здравствуйте! Это мы, хоров+одо в+еды.",
        "buttons": [
            {
                "title": "Надпись на кнопке",
                "payload": {},
                "url": "https://example.com/",
                "hide": true
            }
        ],
        "end_session": false
      },
      "version": "1.0"
    })";
    res.set_content(str, "text/json; charset=UTF-8");
}

std::string textOfReloadPage() {
    std::string pathWebhooks = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\webhooks.json)";
    std::ifstream webhooksFile;
    webhooksFile.open(pathWebhooks);
    std::string startWebhooks = u8R"({
    "webhooks":[]
    })";
    std::string checkFile;
    getline(webhooksFile, checkFile, '\0');
    if (checkFile == "") {
        webhooksFile >> startWebhooks;
    }

    std::string pathTemplateFile = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\template.html)";
    std::ifstream templateFile;
    templateFile.open(pathTemplateFile);
    std::string result;
    getline(templateFile, result, '\0');

    std::string replaceText;
    json hooks;
    hooks = json::parse(webhooksFile);
    int i;
    for (i = 0; i < hooks.size(); i++) {
        replaceText.replace(replaceText.find(u8"{ Webhook URL }"), 15, hooks[i].get<std::string>());
    }
    if (i == 0) replaceText.replace(replaceText.find(u8"{ Webhook URL }"), 15, "");
    result.replace(result.find(u8"{webhooks_list}"), 15, replaceText);
    return replaceText;
}

void gen_response_webhooks_get(const Request& req, Response& res) {
    res.set_content(textOfReloadPage(), "text/json; charset=UTF-8");
}

void gen_response_webhooks_post(const Request& req, Response& res) {
    std::string pathWebhooks = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\webhooks.json)";
    std::ifstream webhooksFile;
    webhooksFile.open(pathWebhooks);
    json File;
    webhooksFile >> File;

    if (req.has_param("del")) {
        auto val = req.get_param_value("del");
        int i;
        for (i = 0; i < File["webhooks"].size(); i++) {
            if(val == File["webhooks"][i]) File["webhooks"].erase(File["webhooks"].begin() + i);
        }
    }

    if (req.has_param("set")) {
        auto val = req.get_param_value("set");
        File["webhooks"].push_back(val);

    }

    
    res.set_content(textOfReloadPage(), "text/json; charset=UTF-8");
}
int main() {
    Server svr;
    svr.Post("/", gen_response);
    svr.Get("/webhooks", gen_response_webhooks_get);
    svr.Post("/webhooks", gen_response_webhooks_post);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 1234);

}

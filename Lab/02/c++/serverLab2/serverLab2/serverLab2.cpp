
#include <iostream>
#include <string>
#include <httplib.h>
#include <json.hpp>

using json = nlohmann::json;

using namespace httplib;
using namespace nlohmann;

template <typename T>
std::string toString(T val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

enum mode {
    basic,
    help
};

json button_basic = json::parse(u8R"({
"title": "Помощь",
"hide": true
})");

json button_help = json::parse(u8R"([
{
"title": "Помощь",
"hide": true
},
{
"title": "Корзина",
"hide": true
},
{
"title": "Выйти из помощи",
"hide": true
},
{
"title": "Покупка завершена",
"hide": true
},
{
"title": "Сумма",
"hide": true
},
{
"title": "Что в корзине",
"hide": true
}
])");


json templateOfRes = json::parse(u8R"({
"response": {
    "text": "",
    "tts": "",
    "buttons": [] ,
    "end_session": false
},
"session_state": {} ,
"version": "1.0"
})");

json templateOfState = json::parse(u8R"({
"mode": 0,
"basket": []
})");

json response(std::string& text, std::string& tts, bool& end_session, json& session_state) {
    std::cout << u8"запустилась функция response \n";
    json templete = templateOfRes;
    templete["response"]["text"] = text;
    templete["response"]["tts"] = tts;
    templete["response"]["end_session"] = end_session;
    templete["session_state"] = session_state;
    if (session_state["mode"] == help) {
        templete["response"]["buttons"] = button_help;
    }
    else {
        templete["response"]["buttons"].push_back(button_basic);
    }
    return templete;
}

void gen_response(const Request& req, Response& res) {
    
    
    std::cout << u8"запустилась функция gen_response \n";
    json result;
    
    json info = json::parse(req.body);
    
    std::string text = u8"";
    std::string tts = u8"";
    json buttons = json::array();
    bool end_session = false;
    json session_state = templateOfState;
    json state = info["state"]["session"];
    std::string user_id = info["session"]["application"]["application_id"];

    session_state = state;



    if (info["session"]["new"].get<bool>()) {
        text = u8"Здравствуйте! Я помогу вам с покупками.";
        tts = u8"Здр+авствуйте! sil <[200]> Я помогу вам с покупками.";
        session_state["mode"] = basic;
    }
    else {

        std::string command = info["request"]["command"];
        if (state["mode"] == help) {
            if (command == u8"помощь")
            {
                text =
                    u8R"(Это то, где вы сейчас находитесь.
                    В этом режиме я расскажу вам подробно о своих возможностях.)";
                tts =
                    u8R"(Это то, где вы сейчас находитесь.
                    В этом режиме я расскажу вам подробно о своих возможностях.)";
            }
            else if (command == u8"корзина")
            {
                text =
                    u8R"(Я запомню, что вы будете добавлять или удалять из корзины.
                    Чтобы добавить что-то, скажите "Добавить в корзину сыр 5 рублей".
                    Чтобы удалить что-то, скажите "Удалить из корзины сыр".)";
                tts =
                    u8R"(Я запомню, что вы будете добавлять или удалять из корзины.
                    Чтобы добавить что-то, скажите "Добавить в корзину сыр 5 рублей".
                    Чтобы удалить что-то, скажите "Удалить из корзины сыр".)";
            }
            else if (command == u8"сумма")
            {
                text = u8"Я подсчитаю стоимость всех товаров в вашей корзине и назову их общую стоимость.";
                tts = u8"Я подсчитаю стоимость всех товаров в вашей корзине и назову их общую стоимость.";
            }
            else if (command == u8"покупка завершена")
            {
                text = u8"Я передам список ваших покупок веб-хукам, после чего очищу корзину.";
                tts = u8"Я передам список ваших покупок веб-хукам, после чего очищу корзину.";
            }
            else if (command == u8"что в корзине") {
                text = u8"Я назову вам все позиции находящиеся в корзине в данный момент.";
                tts = u8"Я назов+у вам все позиции наход+ящиеся в корзине в данный момент.";
            }
            else if (command == u8"выйти из помощи")
            {
                text = u8"Выхожу. Нужна будет помощь - обращайтесь.";
                tts = u8"Выхож+у. Нужна будет помощь - обращайтесь.";
                session_state["mode"] = basic;
            }
            else {
                text = u8"С этим я не могу вам помочь.";
                tts = u8"С +этим я не мог+у вам пом+очь.";
            }
        }
        else {
            if (command == u8"помощь")
            {
                text =
                    u8R"(Говорить или молчать. Включает и выключает голосовой режим.
                    Корзина. Позволяет вести список покупок, а так же их совершать.
                    Помощь. Рассказывает о возможностях этого навыка.
                    Совершить покупку. Очищает корзину и сохраняет данные в формате эксель.
                    Сумма. Считает сумму товаров и называет её вам.
                    О чём рассказать подробнее?)";
                tts =
                    u8R"(Говорить или молчать. Включает и выключает голосовой режим.
                    Корзина. Позволяет вести список покупок, а так же их совершать.
                    Помощь. Рассказывает о возможностях этого навыка.
                    Совершить покупку. Очищает корзину и сохраняет данные в формате эксель.
                    Сумма. Считает сумму товаров и называет её вам.
                    О чём рассказать подробнее?)";
                session_state["mode"] = help;
            }
            else if (command == u8"очистить корзину")
            {
                text = u8"Корзина пуста.";
                tts = u8"Кориз+ина пуст+а.";
                session_state.erase("basket");
                session_state["basket"] = json::array();
            }
            else if (command == u8"что в корзине")
            {
                if (state["basket"].empty())
                {
                    text = u8"На данный момент ваша корзина пуста.";
                    tts = u8"На данный момент ваша корзина пуста.";
                }
                else
                {
                    text = u8"На данный момент в вашей корзине:";
                    for (auto& product : state["basket"])
                    {
                        int price = product["price"].get<int>();

                        text += "\n"
                            + product["item"].get<std::string>()
                            + u8" ценой "
                            + std::to_string(price);

                        if (price % 10 == 0)
                        {
                            text += u8" рублей,";
                        }
                        else if (price > 4 && price < 21)
                        {
                            text += u8" рублей,";
                        }
                        else if (price % 10 == 1)
                        {
                            text += u8" рубль,";
                        }
                        else if (price % 10 < 5 && price % 10 > 1)
                        {
                            text += u8" рубля,";
                        }
                        else
                        {
                            text += u8" рублей,";
                        }
                    }
                    text.pop_back();
                    text.push_back('.');
                    tts = text;
                }
            }
            else if (command == u8"покупка завершена")
            {
                text = u8"Заходите ещё!";
                tts = u8"Заход+ите ещ+ё!";

                json output =
                {
                    {"user_id", user_id},
                    {"check", state["basket"]}
                };

                std::string pathWebhooks = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\webhooks.json)";
                std::ifstream webhooksFile;
                webhooksFile.open(pathWebhooks);
                json hooks;
                if (webhooksFile.is_open()) {

                    hooks = json::parse(webhooksFile);
                }
                else {
                    std::cout << "Проблема с файлом webhooks.json";
                }

                for (int i = 0; i < hooks["webhooks"].size(); i++ )
                {
                    std::string link = toString(hooks["webhooks"][i]);
                    link.erase(link.begin());
                    link.erase(link.end()-1);
                    int index = link.find(u8"//");
                    std::string sub = link.substr(0, index + 2);
                    std::string sub1 = link.substr(index + 2, std::string::npos);
                    Client cli(sub.c_str());
                    cli.Post(sub1.c_str(), output.dump(2), "application/json; charset=UTF-8");
                }
                end_session = true;
                webhooksFile.close();
            }
            else if (command == u8"сумма")
            {
                size_t size = info["request"]["nlu"]["tokens"].size();
                int sum = 0;
                for (auto& cart_item : state["basket"])
                {
                    sum += cart_item["price"].get<int>();
                }
                if (sum == 0)
                {
                    text = u8"У вас в корзине нет товаров.";
                    tts = u8"У вас в корз+ине нет тов+аров.";
                }
                else
                {
                    text = u8"В общей сумме у вас товаров на " + std::to_string(sum);
                    if (sum % 10 == 0)
                    {
                        text += u8" рублей,";
                    }
                    else if (sum > 4 && sum < 21)
                    {
                        text += u8" рублей,";
                    }
                    else if (sum % 10 == 1)
                    {
                        text += u8" рубль,";
                    }
                    else if (sum % 10 < 5 && sum % 10 > 1)
                    {
                        text += u8" рубля,";
                    }
                    else
                    {
                        text += u8" рублей,";
                    }
                    text.pop_back();
                    text.push_back('.');
                    tts = text;
                }
            }
            else if (command.find(u8"добавить в корзину") == 0 || command.find(u8"добавь в корзину") == 0)
            {
                size_t size = info["request"]["nlu"]["tokens"].size();
                text = u8"ОК.";
                tts = u8"Ок+ей.";
                std::string item_name;
                int			item_price = 0;
                int			number_index = 0;
                bool			number_index_set = false;

                for (auto entity : info["request"]["nlu"]["entities"])
                {
                    if (entity["type"].get<std::string>() == u8"YANDEX.NUMBER")
                    {
                        number_index = entity["tokens"]["start"];

                        
                        int val = entity["value"];
                        if (val < 0)
                        {
                            text = u8"Цена не может быть отрицательной.";
                            tts = u8"Цен+а не м+ожет б+ыть отриц+ательной.";
                        }
                        else if (val == 0)
                        {
                            text = u8"Ну кто же вам продаст что-то за бесплатно?";
                            tts = u8"Ну кто же вам прод+аст чт+о то за беспл+атно?";
                        }
                        else
                        {
                            item_price = val;
                        }
                        number_index_set = true;
                        break;
                    }
                }
                if (size == 3)
                {
                    text = u8"Пожалуйста, расскажите, что добавить в корзину.";
                    tts = u8"Пож+алуйста, расскаж+ите, что доб+авить в корз+ину.";
                }
                else if (!number_index_set)
                {
                    text = u8"Пожалуйста, укажите цену товара.";
                    tts = u8"Пож+алуйста, укаж+ите ц+ену тов+ара.";
                }
                else if (number_index == 3)
                {
                    text = u8"Покажуйста, укажите название товара.";
                    tts = u8"Пож+алуйста, укаж+ите назв+ание тов+ара.";
                }
                else
                {
                    for (int i = 3; i < number_index; ++i)
                    {
                        item_name += info["request"]["nlu"]["tokens"][i].get<std::string>();
                        item_name += " ";
                    }
                    item_name.pop_back();
                    json item = {
                        {"item",  item_name},
                        {"price", item_price}
                    };
                    session_state["basket"].push_back(item);
                }
            }
            else if (command.find(u8"удалить из корзины") == 0 || command.find(u8"удали из корзины") == 0 || command.find(u8"убрать из корзины") == 0 || command.find(u8"убери из корзины") == 0)
            {
                size_t size = info["request"]["nlu"]["tokens"].size();

                std::string item_name = "";

                for (int i = 3; i < size; ++i)
                {
                    item_name += info["request"]["nlu"]["tokens"][i].get<std::string>();
                    item_name += " ";
                }
                bool isfound = false;
                int	item_index = 0;

                if (item_name == "")
                {
                    text = u8"Ну вы хоть скажите, что собираетесь убирать.";
                    tts = u8"Ну вы хоть скаж+ите, что собир+аетесь убир+ать.";
                }
                else
                {
                    item_name.pop_back();
                    for (auto& basket_item : session_state["basket"])
                    {
                        if (basket_item["item"].get<std::string>() == item_name)
                        {
                            isfound = true;
                            break;
                        }
                        ++item_index;
                    }
                    if (!isfound)
                    {

                        text = u8"Такого в вашей корзине нету";
                        tts = u8"Так+ого в в+ашей корз+ине н+ету.";
                    }
                    else
                    {

                        text = u8"Удалила.";
                        tts = u8"Удал+ила";
                        session_state["basket"].erase(session_state["basket"].begin() + item_index);

                    }
                }
            }
            else
            {
                text = u8"Я не знаю такую команду.";
                tts = u8"Я не зн+аю так+ую ком+анду.";
            }
        }
    }

    result = response(
        text,
        tts,
        end_session,
        session_state);
    std::cout << result;
    res.set_content(result.dump(), "text/json; charset=UTF-8");

}

std::string textOfReloadPage() {
    std::cout << u8"запустилась функция textOfReloadPage \n";
    std::string result;
    json hooks;
    std::string pathWebhooks = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\webhooks.json)";
    std::ifstream webhooksFile;
    webhooksFile.open(pathWebhooks);
    if (webhooksFile.is_open()) {
        std::string startWebhooksStr = u8R"({
        "webhooks":[]
        })";
        json startWebhooks = json::parse(startWebhooksStr);
        std::string checkFile;
        getline(webhooksFile, checkFile, '\0');
        if (checkFile == u8"") {
            hooks = startWebhooks;
            std::ofstream owebhooksFile(pathWebhooks);
            if (owebhooksFile.is_open()) {
                owebhooksFile << startWebhooks;
                owebhooksFile.close();
            }
            else {
                std::cout << u8"файл owebhooksFile не открылся";
            }
        }
        else {
            hooks = json::parse(checkFile);
        }

        std::string pathTemplateFile = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\template.html)";
        std::ifstream templateFile;
        templateFile.open(pathTemplateFile);
        if (templateFile.is_open()) {
            getline(templateFile, result, '\0');

            std::string replaceText = u8"";
            std::string onehook = u8R"(
            <div class="form-row align-items-center">
                <div class="col">
                  <input type="text" value="{Webhook URL}" class="form-control mb-2" disabled>
                </div>
 
                <div class="col">
                    <button type="submit" name="del" value="{Webhook URL}" class="btn btn-danger mb-2">Удалить</button>
                </div>
            </div>)";

            int i;
            for (i = 0; i < hooks["webhooks"].size(); i++) {
                replaceText += onehook;
                auto val1 = hooks["webhooks"].size();
                auto val2 = replaceText.find(u8"{Webhook URL}");
                auto val3 = toString(hooks["webhooks"][i].get<std::string>());
                replaceText.replace(replaceText.find(u8"{Webhook URL}"), 13, toString(hooks["webhooks"][i].get<std::string>()));
                replaceText.replace(replaceText.find(u8"{Webhook URL}"), 13, toString(hooks["webhooks"][i].get<std::string>()));
            }
            result.replace(result.find(u8"{webhooks_list}"), 15, replaceText);
            templateFile.close();
        }
        webhooksFile.close();
    }
    else {
        std::cout << u8"файл webhooksFile не открылся\n";
    }
    
    return result;
}

void gen_response_webhooks_get(const Request& req, Response& res) {
    std::cout << u8"запустилась функция gen_response_webhooks_get \n";

    res.set_content(textOfReloadPage(), "text/html; charset=UTF-8");
}

void gen_response_webhooks_post(const Request& req, Response& res) {
    std::cout << u8"запустилась функция gen_response_webhooks_post \n";
    std::string result;
    std::string pathWebhooks = u8R"(C:\Users\Никита\Desktop\Programming\Lab\02\c++\serverLab2\serverLab2\webhooks.json)";
    std::ifstream webhooksFile;
    webhooksFile.open(pathWebhooks);
    if (webhooksFile.is_open()) {
        json File;
        std::string tempStrFile = u8"";
        getline(webhooksFile, tempStrFile, '\0');
        
        File = json::parse(tempStrFile);
        std::ofstream owebhooksFile(pathWebhooks);
        if (req.has_param("del")) {
            auto val = req.get_param_value("del");
            int i;
            for (i = 0; i < File["webhooks"].size(); i++) {
                if (val == File["webhooks"][i]) {
                    File["webhooks"].erase(File["webhooks"].begin() + i);
                    owebhooksFile << File;
                    result = textOfReloadPage();
                }
            }
        }

        if (req.has_param("set")) {
            auto val = req.get_param_value("set");

            if ((val.find("http://") != 0 || val.find("https://") != 0) && val.find("//") == std::string::npos  )
            {
                auto val1 = val.find("http://");
                auto val2 = val.find("//");
                auto val3 = val.find("https://");
                result = textOfReloadPage();
                result.replace(result.find(u8"Webhook URL"), 11, u8"Ссылка не валидна! Попробуйте еще раз.");
            }
            else {
                File["webhooks"].push_back(val);
                owebhooksFile << File;
                owebhooksFile.close();
                result = textOfReloadPage();
            }
        }
    }
    else {
        std::cout << u8"файл webhooksFile не открылся";
    }
    webhooksFile.close();
    res.set_content(result, "text/html; charset=UTF-8");
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "C");
    setlocale(LC_CTYPE, ".UTF-8");
    Server svr;
    svr.Post("/", gen_response);
    svr.Get("/webhooks", gen_response_webhooks_get);
    svr.Post("/webhooks", gen_response_webhooks_post);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 1234);

}

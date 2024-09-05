#include "save_load_chat.h"

#include "help.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;

void save_chat(const String& path)
{   
    json j;


    j["count"]["messages"] = AbstractMessage::count();

    for (int i = 0; i < AbstractMessage::count(); ++i)
    {
        String msg_n = "message_" + String::number(i + 1);

        j[msg_n.toStdString().c_str()]["type"]        = AbstractMessage::messages[i]->message_data.message_type;
        j[msg_n.toStdString().c_str()]["time"]        = AbstractMessage::messages[i]->message_data.time.toStdString();
        j[msg_n.toStdString().c_str()]["user_name"]   = AbstractMessage::messages[i]->message_data.user_name.toStdString();
        j[msg_n.toStdString().c_str()]["data"]        = AbstractMessage::messages[i]->message_data.data.toStdString();
    }

    std::string end_path = path.toStdString() + (std::string)"/chat_history.json";
    std::ofstream outputFile(end_path);

    if (outputFile.is_open())
    {
        outputFile << j.dump(4);
        outputFile.close();
        std::cout << "chat is saved\n" << std::endl;
    } 
    else 
    {
        std::cout << "chat saved is failure\n" << std::endl;
    }
}

void load_chat(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, const String& path)
{
    if (read(path + "/chat_history.json").isEmpty()) {
        throw FILE_IS_EMPTY;
    }

    json j;

    std::string end_path = path.toStdString() + (std::string)"/chat_history.json";
    std::ifstream inputFile(end_path);

    if (inputFile.is_open()) 
    {
        inputFile >> j;
        inputFile.close();
    } 
    else 
    {
        std::cout << "Не удалось открыть файл: " << std::endl;
        return;
    }


    int n = j["count"]["messages"];


    for (int i = 0; i < n; ++i)
    {
        String msg_n = "message_" + String::number(i + 1);

        u_sh            _type        = j[msg_n.toStdString()]["type"];
        std::string     _time        = j[msg_n.toStdString()]["time"];
        std::string     _user_name   = j[msg_n.toStdString()]["user_name"];
        std::string     _data        = j[msg_n.toStdString()]["data"];



        u_sh position = AbstractMessage::count() % 2 == 0 ? MessagePosition::RIGHT : MessagePosition::LEFT;

        if (_type == MessageType::TEXT)
        {
            AbstractMessage* newTextMessage = new TextMessage(scrollWidget, parent, centralWidget, position
            , String::fromStdString(_data), String::fromStdString(_time), String::fromStdString(_user_name));
        } 
        else
        {
            AbstractMessage* newPhotoMessage = new PhotoMessage(scrollWidget, parent, centralWidget, position
            , String::fromStdString(_data), String::fromStdString(_time), String::fromStdString(_user_name));
        }   
    }
}
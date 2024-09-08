#include "user.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;


void set_user_name(const String& new_user_name)
{
    user_name = new_user_name;
}

void load_user_name_from_json(const String& json_path)
{
    File file(json_path + "/config.json");
    
    if (!file.exists())
    {
        create_json(json_path + "/config.json");

        load_user_name_from_json(json_path);
    }

    json j;

    std::string end_path = json_path.toStdString() + (std::string)"/config.json";
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

    std::string user_name_from_json = j["user_name"];

    set_user_name(String::fromStdString(user_name_from_json));
}

void save_user_name_to_json(const String& json_path)
{
    json j;

    j["user_name"] = user_name.toStdString();

    std::string end_path = json_path.toStdString() + (std::string)"/config.json";
    std::ofstream outputFile(end_path);

    if (outputFile.is_open())
    {
        outputFile << j.dump(4);
        outputFile.close();
        std::cout << "config is saved\n" << std::endl;
    } 
    else 
    {
        std::cout << "config saved is failure\n" << std::endl;
    }
}

void create_json(const String& json_path)
{

	File file(json_path);

    file.open(QIODevice::WriteOnly);
    file.close();

    String inf = "file " + json_path + "was created";

    MessageBox::information(nullptr, "Information", inf);
}

String get_user_name()
{
    return user_name;
}
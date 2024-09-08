#ifndef USER_H
#define USER_H

#include "include/include.h"

static String user_name;

void set_user_name(const String& new_user_name);
void load_user_name_from_json(const String& json_path);
void save_user_name_to_json(const String& json_path);
void create_json(const String& json_path);
String get_user_name();

#endif // USER_H
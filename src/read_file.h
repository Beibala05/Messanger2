#ifndef READ_FILE_H
#define READ_FILE_H

#include "include/include.h"

#include <string>

String read(const String& path);
String read(const std::string& path);
String read(const char* path);

#endif // READ_FILE_H
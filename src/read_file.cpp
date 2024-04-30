#include "read_file.h"

String read(const String& path)
{
        File file(path);
	file.open(QIODevice::ReadOnly);
	String data = file.readAll();
	file.close();

        return data;
}

String read(const std::string& path)
{
        File file(String::fromStdString(path));
	file.open(QIODevice::ReadOnly);
	String data = file.readAll();
	file.close();

        return data;
}

String read(const char* path)
{
        std::string stdstr = path;
        File file(String::fromStdString(stdstr));
	file.open(QIODevice::ReadOnly);
	String data = file.readAll();
	file.close();

        return data;
}
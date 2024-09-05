#include "help.h"

String read(const String& path)
{
    File file(path);
	file.open(QIODevice::ReadOnly);
	String data = file.readAll();
	file.close();

    return data;
}

void toClipboard(const String& data)
{
	Application::clipboard()->setText(data);
}

String fromClipboard()
{
	return Application::clipboard()->text();
}

void createJSON(const String& path)
{
	if (path.isEmpty())
    {
		throw PATH_IS_EMPTY;
    }

	File file(path + "/chat_history.json");

	if (!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        file.close();

		String inf = "file " + path + "/chat_history.json created";

		MessageBox::information(nullptr, "Information", inf);
    }
}
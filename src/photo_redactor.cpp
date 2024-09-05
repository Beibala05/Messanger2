#include "photo_redactor.h"

#include "help.h"

Widget*     PhotoRedactor::window   = nullptr;
Label*      PhotoRedactor::photo    = nullptr;


PhotoRedactor::PhotoRedactor()
{
    window = new Widget();
    window->resize(1200, 800);
    window->setMinimumSize(1200, 800);
    window->setMaximumSize(1200, 800);
    window->setWindowTitle("Photo");
    window->setStyleSheet(read("../styles/chat.css"));
    window->setWindowModality(Qt::ApplicationModal);

    photo = new Label(window); 
    photo->setAlignment(Qt::AlignCenter);
    photo->setGeometry(0, 0, 1200, 800);

    window->hide();
}


PhotoRedactor::~PhotoRedactor()
{
    delete window;
}

void PhotoRedactor::onFullScreen(const String& file_path)
{
    Pixmap pixmap(file_path);
    photo->setPixmap(pixmap);
    window->show();
}
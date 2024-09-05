#include "photo_message.h"

#include "../help.h"
#include "../messanger/scroll_chat.h"

#include <string>
#include <iostream>

int PhotoMessage::photoMessageHeight = 350;

PhotoMessage::PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& filePath)
{
        this->message_data.data = filePath;
        this->message_data.message_type = MessageType::PHOTO;
        this->message_data.time = this->getCurrentTime();
        this->message_data.user_name = this->getUserName();

        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        photo_path = filePath;

        Pixmap pixmap(filePath);

        image = new Label(this);
        image->setStyleSheet(read("../styles/message_item.css"));
        image->setAlignment(Qt::AlignCenter);
        image->setPixmap(pixmap);    
        image->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, PhotoMessage::photoMessageHeight - 40);

        full_screen = new PushButton(this);
        full_screen->setGeometry(470, 5, 20, 20);
        full_screen->setStyleSheet(read("../styles/copy_text_from_message_button.css"));
        full_screen->setIcon(Icon("../res/messages/full_screen.png"));
        full_screen->setIconSize(Size(20, 20));

        Object::connect(full_screen, &PushButton::clicked, this, &PhotoMessage::fullScreenSlot);

        this->setSizes(position, PhotoMessage::photoMessageHeight);
        ScrollChat::addChatHeight(PhotoMessage::photoMessageHeight);

        MainWindow* mainWindow = qobject_cast<MainWindow *>(centralWidget->parentWidget());

        if (mainWindow) {
                parent->setFixedSize(mainWindow->width(), ScrollChat::getChatHeight());
        }

        this->show();
}

PhotoMessage::PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& filePath, const String& time, const String& userName)
{
        this->message_data.data = filePath;
        this->message_data.message_type = MessageType::PHOTO;
        this->message_data.time = time;
        this->message_data.user_name = userName;

        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        photo_path = filePath;

        Pixmap pixmap(filePath);

        image = new Label(this);
        image->setStyleSheet(read("../styles/message_item.css"));
        image->setAlignment(Qt::AlignCenter);
        image->setPixmap(pixmap);    
        image->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, PhotoMessage::photoMessageHeight - 40);

        full_screen = new PushButton(this);
        full_screen->setGeometry(470, 5, 20, 20);
        full_screen->setStyleSheet(read("../styles/copy_text_from_message_button.css"));
        full_screen->setIcon(Icon("../res/messages/full_screen.png"));
        full_screen->setIconSize(Size(20, 20));

        Object::connect(full_screen, &PushButton::clicked, this, &PhotoMessage::fullScreenSlot);

        this->setSizes(position, PhotoMessage::photoMessageHeight);
        ScrollChat::addChatHeight(PhotoMessage::photoMessageHeight);

        MainWindow* mainWindow = qobject_cast<MainWindow *>(centralWidget->parentWidget());

        if (mainWindow) {
                parent->setFixedSize(mainWindow->width(), ScrollChat::getChatHeight());
        }

        this->show();
}


void PhotoMessage::fullScreenSlot()
{
        PhotoRedactor::onFullScreen(photo_path);
}
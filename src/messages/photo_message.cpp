#include "photo_message.h"

#include "../read_file.h"
#include "../messanger/scroll_chat.h"

#include <string>

int PhotoMessage::photoMessageHeight = 350;

PhotoMessage::PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& filePath)
{
        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        Pixmap pixmap(filePath);

        image = new Label(this);
        image->setStyleSheet(read("../styles/message_item.css"));
        image->setAlignment(Qt::AlignCenter);
        image->setPixmap(pixmap);    
        image->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, PhotoMessage::photoMessageHeight - 40);

        this->setSizes(position, PhotoMessage::photoMessageHeight);
        ScrollChat::addChatHeight(PhotoMessage::photoMessageHeight);

        MainWindow* mainWindow = qobject_cast<MainWindow*>(centralWidget->parentWidget());

        if (mainWindow) {
                parent->setFixedSize(mainWindow->width(), ScrollChat::getChatHeight());
        }

        this->show();
}
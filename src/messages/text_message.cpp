#include "text_message.h"

#include "../help.h"
#include "../messanger/scroll_chat.h"

#include <string>
#include <iostream>

int TextMessage::maxSymbolsInLine = 60;

TextMessage::TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& __text)
{
        this->message_data.data = __text;
        this->message_data.message_type = MessageType::TEXT;
        this->message_data.time = this->getCurrentTime();
        this->message_data.user_name = this->getUserName();

        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        int text_size = ((__text.size() / TextMessage::maxSymbolsInLine) + 1) * 20;

        text = new Label(this);
        text->setStyleSheet(read("../styles/message_item.css"));
        text->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        text->setText(parse(__text));    
        text->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, text_size + 10);

        copy_text = new PushButton(this);
        copy_text->setGeometry(470, 5, 20, 20);
        copy_text->setStyleSheet(read("../styles/copy_text_from_message_button.css"));
        copy_text->setIcon(Icon("../res/messages/copy.png"));
        copy_text->setIconSize(Size(20, 20));

        Object::connect(copy_text, &PushButton::clicked, this, &TextMessage::copyMessageTextSlot);

        this->setSizes(position, text_size + 50);
        ScrollChat::addChatHeight(text_size + 50);

        MainWindow* mainWindow = qobject_cast<MainWindow*>(centralWidget->parentWidget());

        if (mainWindow) {
                parent->setFixedSize(mainWindow->width(), ScrollChat::getChatHeight());
        }

        this->show();
}


TextMessage::TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& data, const String& time, const String& userName)
{
        this->message_data.data = data;
        this->message_data.message_type = MessageType::TEXT;
        this->message_data.time = time;
        this->message_data.user_name = userName;

        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        int text_size = ((data.size() / TextMessage::maxSymbolsInLine) + 1) * 20;

        text = new Label(this);
        text->setStyleSheet(read("../styles/message_item.css"));
        text->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        text->setText(parse(data));    
        text->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, text_size + 10);

        copy_text = new PushButton(this);
        copy_text->setGeometry(470, 5, 20, 20);
        copy_text->setStyleSheet(read("../styles/copy_text_from_message_button.css"));
        copy_text->setIcon(Icon("../res/messages/copy.png"));
        copy_text->setIconSize(Size(20, 20));

        Object::connect(copy_text, &PushButton::clicked, this, &TextMessage::copyMessageTextSlot);

        this->setSizes(position, text_size + 50);
        ScrollChat::addChatHeight(text_size + 50);

        MainWindow* mainWindow = qobject_cast<MainWindow*>(centralWidget->parentWidget());

        if (mainWindow) {
                parent->setFixedSize(mainWindow->width(), ScrollChat::getChatHeight());
        }

        this->show();
}

String TextMessage::parse(const String& text)
{       
        std::string outputString;
        std::string inputString = text.toStdString();

        for (int i = 0; i < inputString.length(); i++) 
        {
                outputString += inputString[i];
                if ((i + 1) % TextMessage::maxSymbolsInLine == 0) 
                {
                        outputString += "\n";
                }
        }

        return String::fromStdString(outputString);
}

void TextMessage::copyMessageTextSlot()
{
        toClipboard(text->text());
}
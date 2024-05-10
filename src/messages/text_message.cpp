#include "text_message.h"

#include "../read_file.h"
#include "../messanger/scroll_chat.h"

#include <string>

int TextMessage::maxSymbolsInLine = 60;

TextMessage::TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
, const String& __text)
{
        AbstractMessage::addMessage(this);
        this->setParent(parent);
        this->handOverCentralWidget(centralWidget);

        int text_size = ((__text.size() / TextMessage::maxSymbolsInLine) + 1) * 20;

        text = new Label(this);
        text->setStyleSheet(read("../styles/message_item.css"));
        text->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        text->setText(parse(__text));    
        text->setGeometry(0, 22, AbstractMessage::abstractMessageWidth, text_size);

        this->setSizes(position, text_size + 40);
        ScrollChat::addChatHeight(text_size + 40);

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
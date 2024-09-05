#include "messanger.h"

#include "../help.h"
#include "../messages/abstract.h"
#include "../save_load_chat.h"

Messanger::Messanger(Widget* parent) : MainWindow(parent)
{
        centralWidget = new Widget(this);

        this->setCentralWidget(centralWidget);
        this->setMinimumSize(MINIMUM_MESSAGER_WIDTH, MINIMUM_MESSAGER_HEIGHT);
        this->setStyleSheet(read("../styles/main.css"));
        
        chat  = new ScrollChat(centralWidget);
        tools = new Tools(centralWidget, chat->getChatPtr(), chat->getScrollWidgetPtr());
        ph_redactor = new PhotoRedactor();

        try {
                createJSON(StandardPaths::writableLocation(StandardPaths::HomeLocation));
        }  
        catch (...) {
                MessageBox::critical(nullptr, "Error", "Permision defined error");
        }

        try {
                load_chat(chat->getScrollWidgetPtr(), chat->getChatPtr(), centralWidget
                , StandardPaths::writableLocation(StandardPaths::HomeLocation));
        }
        catch (...) {
                MessageBox::critical(nullptr, "Error", "Error loading the chat");
        }
}

Messanger::~Messanger()
{
        delete tools;
        delete chat;
        delete ph_redactor;

        save_chat(StandardPaths::writableLocation(StandardPaths::HomeLocation));
}

void Messanger::resizeEvent(ResizeEvent* event)
{
        tools->setGeometry(10, height() - 70, width() - 20, 50);
        chat->resizeChat(width(), height());

        AbstractMessage::correctCoordsForRightMessages(width());

        MainWindow::resizeEvent(event);
}
#include "messanger.h"

#include "../read_file.h"
#include "../messages/abstract.h"

Messanger::Messanger(Widget* parent) : MainWindow(parent)
{
        centralWidget = new Widget(this);

        this->setCentralWidget(centralWidget);
        this->setMinimumSize(MINIMUM_MESSAGER_WIDTH, MINIMUM_MESSAGER_HEIGHT);
        this->setStyleSheet(read("../styles/main.css"));
        
        chat  = new ScrollChat(centralWidget);
        tools = new Tools(centralWidget, chat->getChatPtr(), chat->getScrollWidgetPtr());
}

Messanger::~Messanger()
{
        delete tools;
        delete chat;
}

void Messanger::resizeEvent(ResizeEvent* event)
{
        tools->setGeometry(10, height() - 70, width() - 20, 50);
        chat->resizeChat(width(), height());

        AbstractMessage::correctCoordsForRightMessages(width());

        MainWindow::resizeEvent(event);
}
#include "scroll_chat.h"

#include "../help.h"

int ScrollChat::chatHeight = 50;

ScrollChat::ScrollChat(Widget* parent)
{
        chat = new Widget();
        chat->setStyleSheet(read("../styles/chat.css"));

        scrollWidget = new ScrollArea(parent);
        scrollWidget->setStyleSheet(read("../styles/chat.css"));
        scrollWidget->setGeometry(0, 0, MINIMUM_MESSAGER_WIDTH, MINIMUM_MESSAGER_HEIGHT - 70);
        scrollWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollWidget->setWidgetResizable(true);
        scrollWidget->setWidget(chat);
        scrollWidget->show();
}

void ScrollChat::resizeChat(int width, int height)
{
        scrollWidget->setGeometry(0, 0, width, height - 70);
        chat->setFixedSize(width, height);
}

void ScrollChat::addChatHeight(int height)
{
        ScrollChat::chatHeight += height;
}
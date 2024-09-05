#ifndef SCROLL_CHAT_H
#define SCROLL_CHAT_H

#include "../include/include.h"

struct ScrollChat
{
public:
        explicit ScrollChat(Widget* parent);

public:
        void            resizeChat(int width, int height);
        Widget*         getChatPtr() {return this->chat;}
        ScrollArea*     getScrollWidgetPtr() {return this->scrollWidget;}
        static  void    addChatHeight(int height);
        static  int     getChatHeight() {return chatHeight;}

private:
        Widget*         chat;
        ScrollArea*     scrollWidget;
        static int      chatHeight;
};

#endif // SCROLL_CHAT_H
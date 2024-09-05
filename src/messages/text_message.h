#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "../include/include.h"
#include "abstract.h"

class TextMessage : public AbstractMessage
{
public:
        TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& __text);
        
        TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& data, const String& time, const String& userName);

private:
        String parse(const String& __text);
        void copyMessageTextSlot();

private:
        Label*          text;
        PushButton*     copy_text;
        static int      maxSymbolsInLine;
};

#endif // TEXT_MESSAGE_H
#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "../include/include.h"
#include "abstract.h"

class TextMessage : public AbstractMessage
{
public:
        TextMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& __text);

private:
        String parse(const String& __text);

private:
        Label*  text;
};

#endif // TEXT_MESSAGE_H
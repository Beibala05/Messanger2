#ifndef SAVE_LOAD_CHAT_H
#define SAVE_LOAD_CHAT_H

#include "include/include.h"

#include "messages/abstract.h"
#include "messages/text_message.h"
#include "messages/photo_message.h"
#include "messanger/scroll_chat.h"


void save_chat(const String& path);
void load_chat(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, const String& path);


#endif // SAVE_LOAD_CHAT_H
#ifndef PHOTO_MESSAGE_H
#define PHOTO_MESSAGE_H

#include "../include/include.h"
#include "../photo_redactor.h"
#include "abstract.h"

struct PhotoMessage : AbstractMessage
{
        PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& filePath);

        PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& filePath, const String& time, const String& userName);

private:
        void            fullScreenSlot();

        Label*          image;
        PushButton*     full_screen;
        String          photo_path;
        static int      photoMessageHeight;
};

#endif // PHOTO_MESSAGE_H
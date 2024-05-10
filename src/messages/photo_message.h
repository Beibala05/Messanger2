#ifndef PHOTO_MESSAGE_H
#define PHOTO_MESSAGE_H

#include "../include/include.h"
#include "abstract.h"

class PhotoMessage : public AbstractMessage
{
public:
        PhotoMessage(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget, u_sh position
        , const String& filePath);

private:
        Label*  image;
        static int photoMessageHeight;
};
#endif // PHOTO_MESSAGE_H
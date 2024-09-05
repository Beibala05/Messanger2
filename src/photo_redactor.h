#ifndef PHOTO_REDACTOR_H
#define PHOTO_REDACTOR_H

#include "include/include.h"

struct PhotoRedactor
{
    PhotoRedactor();
    ~PhotoRedactor();

    static void onFullScreen(const String& file_path);

private:
    static Widget* window;
    static Label*  photo;
};

#endif // PHOTO_REDACTOR_H
#ifndef MESSANGER_H
#define MESSANGER_H

#include "../include/include.h"
#include "../photo_redactor.h"

#include "tools.h"
#include "scroll_chat.h"

struct Tools;
struct ScrollChat;

struct Messanger : MainWindow
{
        explicit        Messanger(Widget* parent = nullptr);
                        ~Messanger();
        void            show_user_name();

protected:
	void            resizeEvent(ResizeEvent* event) override;

private:
        Widget*         centralWidget;
        Tools*          tools;
        ScrollChat*     chat;
        PhotoRedactor*  ph_redactor;
        PushButton*     user;
        PushButton*     net_connect;
};

#endif // MESSANGER_H
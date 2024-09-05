#ifndef MESSANGER_H
#define MESSANGER_H

#include "../include/include.h"
#include "../photo_redactor.h"

#include "tools.h"
#include "scroll_chat.h"

class Tools;
class ScrollChat;

class Messanger : public MainWindow
{
public:
        explicit Messanger(Widget* parent = nullptr);
        ~Messanger();

protected:
	void resizeEvent(ResizeEvent* event) override;

private:
        Widget*         centralWidget;
        Tools*          tools;
        ScrollChat*     chat;
        PhotoRedactor*  ph_redactor;
};

#endif // MESSANGER_H
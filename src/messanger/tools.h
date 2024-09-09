#ifndef TOOLS_H
#define TOOLS_H

#include "../include/include.h"

struct Tools : Widget
{
        Tools(Widget* parent, Widget* chat, ScrollArea* scrollWidget);


protected:
	void            resizeEvent(ResizeEvent* event) override;


private:
        void            createTextMessageSlot();
        void            shareDataSlot();

        PushButton*     send;
        PushButton*     share;
        LineEdit*       message;
        Widget*         parent;
        Widget*         chat;
        ScrollArea*     scrollWidget;
};

#endif // TOOLS_H
#ifndef TOOLS_H
#define TOOLS_H

#include "../include/include.h"

class Tools : public Widget
{
public:
        Tools(Widget* parent, Widget* chat, ScrollArea* scrollWidget);

protected:
	void resizeEvent(ResizeEvent* event) override;

private:
        void createTextMessageSlot();
        void shareDataSlot();

private:
        PushButton*     send;
        PushButton*     share;
        LineEdit*       message;
        Widget*         parent;
        Widget*         chat;
        ScrollArea*     scrollWidget;
};

#endif // TOOLS_H
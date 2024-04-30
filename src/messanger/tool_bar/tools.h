#ifndef TOOLS_H
#define TOOLS_H

#include "../../include/include.h"

class Tools : public Widget
{
public:
        explicit Tools(Widget* parent);

protected:
	void resizeEvent(ResizeEvent* event) override;

private:
        PushButton*     send;
        PushButton*     share;
        LineEdit*       message;
};

#endif // TOOLS_H
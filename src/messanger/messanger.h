#ifndef MESSANGER_H
#define MESSANGER_H

#include "../include/include.h"

#include "tool_bar/tools.h"

class Tools;

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
};

#endif // MESSANGER_H
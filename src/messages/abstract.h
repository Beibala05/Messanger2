#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include "../include/include.h"

#include <vector>

enum MessagePosition : u_sh
{
        RIGHT,
        LEFT
};

class AbstractMessage : public Widget
{
public:
        AbstractMessage();
        virtual ~AbstractMessage();

public:
        void setSizes(u_sh pos, int height);
        void handOverCentralWidget(Widget* centralWidget);
        static void addMessage(AbstractMessage* message);
        static void correctCoordsForRightMessages(int width);
        static int  count();

public:
        static int abstractMessageWidth;

private:
        String getCurrentTime();

private:
        Label*  userName;
        Label*  time;
        Widget* centralWidget;
        static std::vector<AbstractMessage *> messages;
        u_sh    pos;
};

#endif // ABSTRACT_MESSAGE_H
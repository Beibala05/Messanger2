#ifndef ABSTRACT_MESSAGE_H
#define ABSTRACT_MESSAGE_H

#include "../include/include.h"

#include <vector>

enum MessagePosition : u_sh
{
        RIGHT,
        LEFT
};

enum MessageType : u_sh
{
        PHOTO,
        TEXT        
};

struct MessageData
{
        String  data;
        String  user_name;
        String  time;
        u_sh    message_type;
};

struct AbstractMessage : Widget
{
                                                AbstractMessage();
        virtual                                 ~AbstractMessage();

        void                                    setSizes(u_sh pos, int height);
        void                                    handOverCentralWidget(Widget* centralWidget);
        static void                             addMessage(AbstractMessage* message);
        static void                             correctCoordsForRightMessages(int width);
        static int                              count();
        String                                  getUserNameFromMessage();
        String                                  getCurrentTime();
        Label*                                  getTimePtr();
        Label*                                  getUserNamePtr();

        static int                              abstractMessageWidth;
        static std::vector<AbstractMessage *>   messages;
        MessageData                             message_data;


private:
        Label*                                  userName;
        Label*                                  time;
        Widget*                                 centralWidget;
        u_sh                                    pos;
};

#endif // ABSTRACT_MESSAGE_H
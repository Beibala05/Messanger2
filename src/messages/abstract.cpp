#include "abstract.h"

#include "../help.h"
#include "../messanger/scroll_chat.h"

std::vector<AbstractMessage *> AbstractMessage::messages;
int AbstractMessage::abstractMessageWidth = 500;

AbstractMessage::AbstractMessage()
{
        this->setStyleSheet(read("../styles/message.css"));
        userName = new Label(this);
        userName->setGeometry(0, 0, 230, 20);
        userName->setText("user name");
        userName->setStyleSheet(read("../styles/message_item.css"));

        time = new Label(this);
        time->setText(getCurrentTime());
        time->setAlignment(Qt::AlignRight);
        time->setStyleSheet(read("../styles/message_item.css"));
}

AbstractMessage::~AbstractMessage()
{

}

void AbstractMessage::setSizes(u_sh pos, int height)
{
        MainWindow* mainWindow = qobject_cast<MainWindow*>(centralWidget->parentWidget());
        if (mainWindow)
        {
                if (pos == MessagePosition::RIGHT)
                        this->setGeometry(mainWindow->width() - abstractMessageWidth, ScrollChat::getChatHeight(), abstractMessageWidth, height);
                else
                        this->setGeometry(5, ScrollChat::getChatHeight(), abstractMessageWidth, height);

                time->setGeometry(0, height - 20, abstractMessageWidth, 20);
        }

        this->pos = pos;
}

String AbstractMessage::getCurrentTime()
{
        Time currentTime = Time::currentTime();
        return currentTime.toString("hh:mm:ss");
}

void AbstractMessage::addMessage(AbstractMessage* message)
{
        AbstractMessage::messages.push_back(message);
}

int AbstractMessage::count()
{
        return AbstractMessage::messages.size(); 
}

void AbstractMessage::handOverCentralWidget(Widget* centralWidget)
{
        this->centralWidget = centralWidget;
}

void AbstractMessage::correctCoordsForRightMessages(int width)
{
        for (int i = 0; i < AbstractMessage::messages.size(); ++i)
        {
                if (AbstractMessage::messages[i]->pos == MessagePosition::RIGHT)
                {
                        int y_coor = AbstractMessage::messages[i]->y();
                        AbstractMessage::messages[i]->setGeometry(width - AbstractMessage::abstractMessageWidth, y_coor,
                        AbstractMessage::messages[i]->width(), AbstractMessage::messages[i]->height());
                }
        }
}

String AbstractMessage::getUserName()
{
        return userName->text();
}       
#include "messanger.h"

#include "../help.h"
#include "../messages/abstract.h"
#include "../save_load_chat.h"
#include "../user.h"

#include <thread>

std::shared_ptr<tcp::socket> Messanger::socket_ptr;

Messanger::Messanger(Widget* parent) : MainWindow(parent)
{
        centralWidget = new Widget(this);

        this->setCentralWidget(centralWidget);
        this->setMinimumSize(MINIMUM_MESSAGER_WIDTH, MINIMUM_MESSAGER_HEIGHT);
        this->setStyleSheet(read("../styles/main.css"));
        
        chat  = new ScrollChat(centralWidget);
        tools = new Tools(centralWidget, chat->getChatPtr(), chat->getScrollWidgetPtr());
        ph_redactor = new PhotoRedactor();
        user = new PushButton(centralWidget);
        net_connect = new PushButton(centralWidget);
        message_handler = new MessageHandler(chat->getScrollWidgetPtr(), chat->getChatPtr(), centralWidget);

        user->setGeometry(5, 5, 40, 40);
        user->setStyleSheet(read("../styles/user_wifi_buttons.css"));
        user->setIcon(Icon("../res/user.png"));
        user->setIconSize(Size(40, 40));

        net_connect->setGeometry(60, 5, 40, 40);
        net_connect->setStyleSheet(read("../styles/user_wifi_buttons.css"));
        net_connect->setIcon(Icon("../res/wi_fi.png"));
        net_connect->setIconSize(Size(40, 40));

        Object::connect(user, &PushButton::clicked, this, &Messanger::show_user_name);

        load_user_name_from_json(StandardPaths::writableLocation(StandardPaths::HomeLocation));

        try {
                createJSON(StandardPaths::writableLocation(StandardPaths::HomeLocation));
        }  
        catch (...) {
                MessageBox::critical(nullptr, "Error", "Permision defined error");
        }

        try {
                load_chat(chat->getScrollWidgetPtr(), chat->getChatPtr(), centralWidget
                , StandardPaths::writableLocation(StandardPaths::HomeLocation));
        }
        catch (...) {
                MessageBox::critical(nullptr, "Error", "Error loading the chat");
        }

        QObject::connect(message_handler, SIGNAL(messageReceived(QString)), message_handler, SLOT(handleMessage(QString)), Qt::QueuedConnection);

}

Messanger::~Messanger()
{
        delete tools;
        delete chat;
        delete ph_redactor;
        delete user;
        delete net_connect;
        delete message_handler;

        save_chat(StandardPaths::writableLocation(StandardPaths::HomeLocation));
        save_user_name_to_json(StandardPaths::writableLocation(StandardPaths::HomeLocation));
}

void Messanger::resizeEvent(ResizeEvent* event)
{
        tools->setGeometry(10, height() - 70, width() - 20, 50);
        chat->resizeChat(width(), height());

        AbstractMessage::correctCoordsForRightMessages(width());

        MainWindow::resizeEvent(event);
}

void Messanger::show_user_name()
{
        MessageBox::information(nullptr, "check my user name", "Your current user name is: " + get_user_name() + "\n\n"\
        "Enter the command @new_user_name in message line for set new user name");
}

void Messanger::set_socket_ptr(std::shared_ptr<tcp::socket>& socket)
{
        socket_ptr = socket;
}

std::shared_ptr<tcp::socket> Messanger::get_socket_ptr()
{
        return socket_ptr;
}

void Messanger::run_read_server_thread()
{
        std::thread(net::read_message_from_server
        , socket_ptr
        , chat->getScrollWidgetPtr()
        , chat->getChatPtr()
        , centralWidget
        , message_handler).detach();
}


MessageHandler::MessageHandler(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget)
{
        this->scrollWidget      = scrollWidget;
        this->centralWidget     = centralWidget; 
        this->parent            = parent; 
}

void MessageHandler::handleMessage(const QString& message)
{
        AbstractMessage* newTextMessage = new TextMessage(scrollWidget, parent, centralWidget,
            MessagePosition::LEFT,
            String::fromStdString(message.toStdString()), "00:00:00", "default-user");
        std::cout << "Создано сообщение от сервера: " << message.toStdString() << std::endl;
}
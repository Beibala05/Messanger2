#ifndef MESSANGER_H
#define MESSANGER_H

#include "../include/include.h"
#include "../photo_redactor.h"
#include "../net/client.h"
#include "../net/work.h"

#include "tools.h"
#include "scroll_chat.h"

#include <iostream>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

struct Tools;
struct ScrollChat;

struct MessageHandler : Object 
{
        Q_OBJECT

public:
        MessageHandler(ScrollArea* scrollWidget, Widget* parent, Widget* centralWidget);

public slots:
        void handleMessage(const QString& message);

signals:
        void messageReceived(const QString& message);       

private:
        ScrollArea*     scrollWidget;
        Widget*         centralWidget;
        Widget*         parent;
};

struct Messanger : MainWindow
{
        explicit                                Messanger(Widget* parent = nullptr);
                                                ~Messanger();
        static void                             set_socket_ptr(std::shared_ptr<tcp::socket>& socket);
        static std::shared_ptr<tcp::socket>     get_socket_ptr();
        void                                    run_read_server_thread();
        void                                    show_user_name();

protected:
	void                                    resizeEvent(ResizeEvent* event) override;

private:
        Widget*                                 centralWidget;
        Tools*                                  tools;
        ScrollChat*                             chat;
        PhotoRedactor*                          ph_redactor;
        PushButton*                             user;
        PushButton*                             net_connect;
        MessageHandler*                         message_handler;
        static std::shared_ptr<tcp::socket>     socket_ptr;
};

#endif // MESSANGER_H
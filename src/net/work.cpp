#include "work.h"

#include "../messages/abstract.h"
#include "../messages/text_message.h"
#include "../messages/photo_message.h"

#include <iostream>
#include <thread>

namespace net
{
	void send_message_to_server(std::string message, std::shared_ptr<tcp::socket> socket)
	{
		boost::asio::write(*socket, boost::asio::buffer(message));
	}

	void read_message_from_server(
		std::shared_ptr<tcp::socket> socket
		, ScrollArea* scrollWidget 
		, Widget* parent
		, Widget* centralWidget
		, MessageHandler* message_handler
	)
	{
		char buffer[1024];
	    boost::system::error_code error;

	    while (true)
	    {
	        size_t len = socket->read_some(boost::asio::buffer(buffer), error);

	        if (error) 
	        {
	            std::cerr << "Ошибка чтения: " << error.message() << std::endl;
	            break; // Выход при ошибке
	        }

	        // std::string message_from_server(buffer, len);


	        QString message_from_server = QString::fromStdString(std::string(buffer, len));
        	emit message_handler->messageReceived(message_from_server); // Испускаем сигнал с сообщением
        	std::cout << "Сообщение от сервера: " << message_from_server.toStdString() << std::endl;


	        // AbstractMessage* newTextMessage = new TextMessage(scrollWidget, parent, centralWidget
	        // , MessagePosition::LEFT
	        // , String::fromStdString(message_from_server), "00:00:00", "default-user");

	        // std::cout << "Сообщение от сервера: " << message_from_server << std::endl;
	    }
	}
};
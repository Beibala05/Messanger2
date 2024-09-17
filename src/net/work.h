#ifndef WORK_H
#define WORK_H

#include "../include/include.h"
#include "../messanger/messanger.h"

#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

struct MessageHandler;

namespace net
{
	void send_message_to_server(std::string message, std::shared_ptr<tcp::socket> socket);
	
	void read_message_from_server(std::shared_ptr<tcp::socket> socket
		, ScrollArea* scrollWidget 
		, Widget* parent
		, Widget* centralWidget
		, MessageHandler* message_handler
	);
};

#endif // WORK_H
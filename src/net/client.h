#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace net
{

	struct ClientData
	{
		static boost::asio::io_context	io_context;
		static std::string				address;
		static int 						port;
		static bool						status;
	};

};

#endif // CLIENT_H
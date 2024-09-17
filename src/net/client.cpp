#include "client.h"

boost::asio::io_context net::ClientData::io_context;
std::string				net::ClientData::address		= "127.0.0.1";
int 					net::ClientData::port 			= 12345;
bool					net::ClientData::status			= false;

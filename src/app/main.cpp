#include "../include/include.h"
#include "../messanger/messanger.h"
#include "../net/client.h"
#include "../net/work.h"

#include <iostream>
#include <memory>
#include <thread>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

#ifdef __linux__

struct Messanger;

int main(int argc, char** argv)
{
        Application app(argc, argv);

        Messanger messanger;
        messanger.show();


        tcp::socket socket(net::ClientData::io_context);
        socket.connect(tcp::endpoint(tcp::v4(), net::ClientData::port));


        if (socket.is_open())
        {

                std::cout << "Соединение с сервером установлено" << std::endl;
                // ClientData::status = true;

                std::shared_ptr<tcp::socket> socket_ptr = std::make_shared<tcp::socket>(std::move(socket));
                Messanger::set_socket_ptr(socket_ptr);
                messanger.run_read_server_thread();

                // std::thread(net::read_message_from_server, socket_ptr).detach();


                // send_message_to_server(message_fro_server, socket_ptr)
        }       
        else
        {
                std::cerr << "Сокет не открыт" << std::endl;
        }



        return app.exec();
}

#else
        #error "linux only"
#endif
#include"Server.h"

Server::Server(asio::io_context& io_context, unsigned short port)
    : m_acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
    do_accept();
}

void Server::do_accept()
{
    m_acceptor.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket)
        {
            if (!ec)
            {
                std::cout << "Accepted connection from " << socket.remote_endpoint().address().to_string() << std::endl;
                std::make_shared<Session>(std::move(socket),&m_listUser)->start();
            }
            do_accept();
        });
}
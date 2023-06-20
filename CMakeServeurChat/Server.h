#pragma once
#include"Session.h"

class Server
{
public:
    Server(asio::io_context& io_context, unsigned short port);

private:
    void do_accept();

    asio::ip::tcp::acceptor m_acceptor;
    ListeUser m_listUser;

};

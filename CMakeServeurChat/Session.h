#pragma once
#include "ListeUser.h"
class Session : public std::enable_shared_from_this<Session>
{
public:
    Session(asio::ip::tcp::socket socket,ListeUser* listUser);
    ~Session();

    void start();


private:

    void do_read();
    void analyseData(string data);
    void close();

    void do_timer();

    asio::ip::tcp::socket m_socket;
    asio::steady_timer m_timer;
    enum { max_length = 1024 };
    char m_data[max_length];
    ListeUser* m_listeUser;
    int m_nbConnect;
    User* m_user;
};
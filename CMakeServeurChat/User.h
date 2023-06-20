#pragma once
#include<iostream>
#include"Entete.h"
#include"UserExceptions.h"

class User: public UserException {
public:
	User(std::string ip, std::string number, asio::ip::tcp::socket* socket);
	User(std::string ip, std::string number);
	User();
	~User();
	void writeMessage(std::string msg);
	std::string IP();
	std::string Number();
	void setConnect(bool isConnect);
	bool isConnected() const;
	void exception();

private:
	std::string m_ip;
	std::string m_number;
	asio::ip::tcp::socket* m_socket;
	bool m_isConnect;
};
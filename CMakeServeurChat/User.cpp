#include"User.h"

User::User(std::string ip, std::string number, asio::ip::tcp::socket* socket)
{
	m_ip = ip;
	m_number = number;
	m_socket =socket;
	m_isConnect = true;
}
User::User(std::string ip, std::string number)
{
	m_ip = ip;
	m_number = number;
	m_isConnect = true;
}
User::User()
{
	m_ip = "";
	m_number = "";
}
User::~User()
{
	//delete m_socket;
}
std::string User::IP() {
	return m_ip;
}
std::string User::Number() {
	return m_number;
}
void User::setConnect(bool isConnect)
{
	m_isConnect = isConnect;
}
bool User::isConnected()const
{
	return m_isConnect;
}
void User::exception() {
	throw UserException();
}
void User::writeMessage(std::string msg)
{
	std::cout <<" \n message envoyer " << msg<<" au numero : "<<m_number << std::endl;
	asio::write(*m_socket, asio::buffer(msg.c_str(), msg.length()));
}

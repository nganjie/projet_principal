#include"ListeUser.h"


ListeUser::ListeUser() {

}
ListeUser::~ListeUser()
{
	for (int i = 0; i < m_liste.size(); i++)
		delete m_liste[i];
	
}
void ListeUser::insertUser(User* user) {
	m_liste.push_back(user);
}
void ListeUser::popUser(std::string ipUser, std::string numberUser)
{
	vector<User*>::iterator it;

	for (int i=0;i<m_liste.size();i++)
	{
		if (m_liste[i]->IP() == ipUser && m_liste[i]->Number() == numberUser)
		{
			m_liste.erase(m_liste.begin() + i);
			//erase(m_liste, m_liste[i]);
		}
		
	}
}
string ListeUser::getNumberUser(string ip)
{
	for (int i = 0; i < m_liste.size(); i++)
	{
		if (m_liste[i]->IP() == ip)
		{
			return m_liste[i]->Number();
			//erase(m_liste, m_liste[i]);
		}

	}
	return "";
}
bool ListeUser::isConnect(string number)
{
	for (int i = 0; i < m_liste.size(); i++)
	{
		if (m_liste[i]->Number() == number)
		return true;
	}
	return false;
}
int ListeUser::sizeConnected()
{
	return m_liste.size();
}
User* ListeUser::getUser(string number)
{
	for (int i = 0; i < m_liste.size(); i++)
	{
		if (m_liste[i]->Number() == number)
		{
			return m_liste[i];
			//erase(m_liste, m_liste[i]);
		}

	}
	return new User;
}
void ListeUser::sendMessage(string number, string msg)
{
	if (isConnect(number))
	{
		User* us = ListeUser::getUser(number);
		if (us->Number() != "")
		{
			us->writeMessage(msg);
		}
		else cout << "\n utilisateur introuvable\n";
	}
	else cout << "\n utilisateur non connecter\n";
	

}
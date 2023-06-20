#pragma once
#include<iostream>
#include<vector>
#include"User.h"

using namespace std;

class ListeUser {
public:
	ListeUser();
	~ListeUser();
	void insertUser(User* user);
	void popUser(std::string ipUser, std::string numberUser);
	void sendMessage(string number,string msg);
	int sizeConnected();
	std::string getNumberUser(string ip);
	User* getUser(string number);
	bool isConnect(string number);
private:
	std::vector<User*> m_liste;
	
};

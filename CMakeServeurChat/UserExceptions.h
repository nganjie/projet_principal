#pragma once
#include<iostream>
#include<exception>


class UserException : public std::exception {
public:
	const char* what() const throw(){
		return "utilisateur deconnecter\n";
	}
};
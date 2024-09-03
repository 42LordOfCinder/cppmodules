#include <string>
#include <iostream>
#include "Contact.hpp"

std::string	Contact::getFN(void) {
	return this->firstName;
}

std::string	Contact::getLN(void) {
	return this->lastName;
}

std::string	Contact::getNN(void) {
	return this->nickname;
}

std::string	Contact::getPN(void) {
	return this->phoneNumber;
}

std::string	Contact::getDS(void) {
	return this->darkestSecret;
}

void	Contact::setFN(std::string fN) {
	this->firstName = fN;
}

void	Contact::setLN(std::string lN) {
	this->lastName = lN;
}

void	Contact::setNN(std::string nN) {
	this->nickname = nN;
}

void	Contact::setPN(std::string pN) {
	this->phoneNumber = pN;
}

void	Contact::setDS(std::string dS) {
	this->darkestSecret = dS;
}

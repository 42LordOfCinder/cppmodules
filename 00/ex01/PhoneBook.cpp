#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->i = 0;
}

void	PhoneBook::addContact(void) {
	std::string	input;

	while (!std::cin.eof() && input.empty()) {
		std::cout << "First name: ";
		getline(std::cin, input);
	}
	this->contacts[this->i % 8].setFN(input);

	input.clear();
	while (!std::cin.eof() && input.empty()) {
		std::cout << "Last name: ";
		getline(std::cin, input);
	}
	this->contacts[this->i % 8].setLN(input);

	input.clear();
	while (!std::cin.eof() && input.empty()) {
		std::cout << "Nickname: ";
		getline(std::cin, input);
	}
	this->contacts[this->i % 8].setNN(input);

	input.clear();
	while (!std::cin.eof() && input.empty()) {
		std::cout << "Phone number: ";
		getline(std::cin, input);
	}
	this->contacts[this->i % 8].setPN(input);

	input.clear();
	while (!std::cin.eof() && input.empty()) {
		std::cout << "Darkest secret: ";
		getline(std::cin, input);
	}
	this->contacts[this->i % 8].setDS(input);

	this->i++;
}

void	PhoneBook::printContact(void) {
	int			i = 0;
	int			len;
	std::string	str;
	std::string	input;
	const char	*inputCpy;
	int			index = 0;

	if (this->i == 0) {
		std::cout << "No contact has been registered yet.\n";
		return ;
	}
	while (i < this->i && i < 8) {
		std::cout << "         " << i + 1 << "|";
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				str = this->contacts[i].getFN();
			else if (j == 1)
				str = this->contacts[i].getLN();
			else
				str = this->contacts[i].getNN();
			len = str.length();
			if (len > 10)
				std::cout << str.substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << str;
			if (j != 2)
				std::cout << "|";
		}
		std::cout << std::endl;
		i++;
	}
	while (!std::cin.eof() && (input.empty() || index < 1 || index > this->i || index > 8)) {
		std::cout << "Enter contact index: ";
		getline(std::cin, input);
		inputCpy = input.c_str();
		index = atoi(inputCpy);
	}
	std::cout << this->contacts[index - 1].getFN() << std::endl;
	std::cout << this->contacts[index - 1].getLN() << std::endl;
	std::cout << this->contacts[index - 1].getNN() << std::endl;
	std::cout << this->contacts[index - 1].getPN() << std::endl;
	std::cout << this->contacts[index - 1].getDS() << std::endl;
}

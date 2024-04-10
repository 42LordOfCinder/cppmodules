#include <iostream>
#include <cstring>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void) {
	std::string	input;
	PhoneBook	phoneBook;

	while (1) {
		std::cout << "Enter a command (ADD/SEARCH/EXIT): ";
		getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else if (input == "EXIT")
			break ;
		else if (input == "SEARCH")
			phoneBook.printContact();
		else if (input == "ADD")
			phoneBook.addContact();
		else
			std::cout << "Please enter a valid command\n";
	}
	return 0;
}

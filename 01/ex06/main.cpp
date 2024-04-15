#include <iostream>
#include <string>
#include "Harl.hpp"

int	toInt(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return i + 1;
		}
	}
	return 5;
}

int	main( int argc, char *argv[]) {
	Harl	harl;

	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	switch(toInt(std::string(argv[1]))) {
		case 1:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 2:
			harl.complain("INFO");
			std::cout << std::endl;
		case 3:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}

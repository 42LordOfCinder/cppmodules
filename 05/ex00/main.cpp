#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	Francoislebureaucrate("Francois", 150);
	std::cout << Francoislebureaucrate;
	try {
		Francoislebureaucrate.decr();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Francoislebureaucrate;
	Francoislebureaucrate.incr();
	std::cout << Francoislebureaucrate;
	Bureaucrat Nathanlebureaucrate("Nathan", 1);
	std::cout << Nathanlebureaucrate;
	try {
		Nathanlebureaucrate.incr();
	}
	catch (std::exception &e) {
		std::cerr << e.what() <<std::endl;
	}
	std::cout << Nathanlebureaucrate;
	try {
		Bureaucrat Mateolebureaucrate("Mateo", 200);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

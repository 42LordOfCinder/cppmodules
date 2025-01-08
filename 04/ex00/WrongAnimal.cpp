#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	this->type = "strange rhinoceros";
	std::cout << "Wrong animal created" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal &wr ) {
	this->type = wr.type;
	std::cout << "Wrong animal copied" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wr ) {
	this->type = wr.type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "Wrong animal destroyed" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "strange rhinoceros sounds" << std::endl;
}

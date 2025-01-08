#include "Animal.hpp"

Animal::Animal( void ) {
	this->type = "Rhinoceros";
	std::cout << "Animal created" << std::endl;
}

Animal::Animal( Animal &animal ) {
	this->type = animal.type;
	std::cout << "Animal copied" << std::endl;
}

Animal &Animal::operator=( Animal const &animal ) {
	this->type = animal.type;
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal destroyed" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (this->type);
}

void	Animal::makeSound( void ) const {
	std::cout << "Rhinoceros" << std::endl;
}

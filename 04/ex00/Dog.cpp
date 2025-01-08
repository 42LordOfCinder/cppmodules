#include "Dog.hpp"

Dog::Dog( void ) {
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog( Dog &dog ) : Animal(dog) {
	this->type = dog.getType();
	std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=( Dog const &dog ) {
	this->type = dog.type;
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destroyed" << std::endl;
}

std::string	Dog::getType( void ) const {
	return (this->type);
}

void	Dog::makeSound( void ) const {
	std::cout << "wāngwāng" << std::endl;
}

#include "Dog.hpp"

Dog::Dog( void ) {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::Dog( Dog &dog ) : Animal(dog) {
	this->type = dog.getType();
	this->brain = new Brain(*(dog.getBrain()));
	std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=( Dog const &dog ) {
	this->type = dog.type;
	if ( this->brain )
		delete this->brain;
	this->brain = new Brain(*(dog.getBrain()));
	return (*this);
}

Dog::~Dog( void ) {
	delete this->brain;
	std::cout << "Dog destroyed" << std::endl;
}

std::string	Dog::getType( void ) const {
	return (this->type);
}

void	Dog::makeSound( void ) const {
	std::cout << "wāngwāng" << std::endl;
}

Brain	*Dog::getBrain( void ) const {
	return (this->brain);
}

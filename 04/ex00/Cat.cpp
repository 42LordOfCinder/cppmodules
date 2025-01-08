#include "Cat.hpp"

Cat::Cat( void ) {
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat( Cat &cat ) : Animal(cat) {
	this->type = cat.getType();
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=( Cat const &cat ) {
	this->type = cat.type;
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destroyed" << std::endl;
}

std::string	Cat::getType( void ) const {
	return (this->type);
}

void	Cat::makeSound( void ) const {
	std::cout << "miāo miāo" << std::endl;
}

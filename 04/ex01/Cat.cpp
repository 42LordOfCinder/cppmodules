#include "Cat.hpp"

Cat::Cat( void ) {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::Cat( Cat &cat ) : Animal(cat) {
	this->type = cat.getType();
	this->brain = new Brain(*(cat.getBrain()));
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=( Cat const &cat ) {
	this->type = cat.type;
	if ( this->brain )
		delete this->brain;
	this->brain = new Brain(*(cat.getBrain()));
	return (*this);
}

Cat::~Cat( void ) {
	delete this->brain;
	std::cout << "Cat destroyed" << std::endl;
}

std::string	Cat::getType( void ) const {
	return (this->type);
}

void	Cat::makeSound( void ) const {
	std::cout << "miāo miāo" << std::endl;
}

Brain	*Cat::getBrain( void ) const {
	return (this->brain);
}

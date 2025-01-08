#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	this->type = "strange cat";
	std::cout << "Wrong cat created" << std::endl;
}

WrongCat::WrongCat( WrongCat &wc ) : WrongAnimal(wc) {
	this->type = wc.getType();
	std::cout << "Wrong cat copied" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &wc ) {
	this->type = wc.type;
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "Wrong cat destroyed" << std::endl;
}

std::string	WrongCat::getType( void ) const {
	return (this->type);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "strange chinese cat sound" << std::endl;
}

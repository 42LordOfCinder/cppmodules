#include "Weapon.hpp"

Weapon::~Weapon(void) {}

std::string	&Weapon::getType(void) {
	return this->type;
}

void	Weapon::setType(std::string newType) {
	this->type = newType;
}

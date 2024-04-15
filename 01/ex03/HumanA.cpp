#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(void) {}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

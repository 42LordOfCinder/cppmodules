#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " anihilated." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

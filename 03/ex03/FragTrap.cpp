#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap produced!" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " produced!" << std::endl;
}

FragTrap::FragTrap( FragTrap const &fragTrap ): ClapTrap(fragTrap) {
	std::cout << "FragTrap " << fragTrap.name << " reproduced!" << std::endl;
	*this = fragTrap;
}

FragTrap	&FragTrap::operator=( FragTrap const &fragTrap ) {
	if (this != &fragTrap) {
		this->hitPoints = fragTrap.hitPoints;
		this->energyPoints = fragTrap.energyPoints;
		this->attackDamage = fragTrap.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << this->name << " demolished!" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name << " accepts the high five!" << std::endl;
}

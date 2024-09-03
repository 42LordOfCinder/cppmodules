#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ScavTrap(), FragTrap() {
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap built!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): DiamondTrap(name) {
	ScavTrap::name = name;
	FragTrap::name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " built!" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << this->name << " disintegrated!" << std::endl;
}

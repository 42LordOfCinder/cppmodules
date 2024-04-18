#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->gateKeeperMode = false;
	std::cout << "ScavTrap built!" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->gateKeeperMode = false;
	std::cout << "ScavTrap " << name << " built!" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &scavTrap ): ClapTrap(scavTrap) {
	std::cout << "ScavTrap " << scavTrap.name << " copied!" << std::endl;
	*this = scavTrap;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &scavTrap ) {
	if (this != &scavTrap) {
		this->hitPoints = scavTrap.hitPoints;
		this->energyPoints = scavTrap.energyPoints;
		this->attackDamage = scavTrap.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	if (!this->gateKeeperMode) {
		this->gateKeeperMode = true;
		std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name << " is already in Gate keeper mode!" << std::endl;
	}
}

void	ScavTrap::attack( const std::string target ) {
	if (this->energyPoints == 0) {
		std::cout << "ScavTrap " << this->name << " has no energy left!" << std::endl;
		return ;
	}
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " seems out of order..." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attackDamage << " points of damage!" << std::endl;
}

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap() {
	ScavTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	ScavTrap::attackDamage = 20;
	ScavTrap::gateKeeperMode = false;
	std::cout << "ScavTrap made!" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name) {
	ScavTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	ScavTrap::attackDamage = 20;
	ScavTrap::gateKeeperMode = false;
	std::cout << "ScavTrap " << name << " made!" << std::endl;
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
	std::cout << "ScavTrap " << this->name << " broke!" << std::endl;
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
		std::cout << "ScavTrap " << this->name << " is no energyzed anymore!" << std::endl;
		return ;
	}
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " seems broke..." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " assaults " << target << ", dealing ";
	std::cout << this->attackDamage << " points of damage!" << std::endl;
}

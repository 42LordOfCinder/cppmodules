#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap built!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " built!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &clapTrap ) {
	std::cout << "ClapTrap " << clapTrap.name << " copied!" << std::endl;
	*this = clapTrap;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &clapTrap ) {
	if (this != &clapTrap ) {
		this->hitPoints = clapTrap.hitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->attackDamage = clapTrap.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void	ClapTrap::attack( const std::string target ) {
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy left!" << std::endl;
		return ;
	}
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " seems out of order..." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing ";
	std::cout << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints > 0) {
		if (amount > this->hitPoints)
			this->hitPoints = 0;
		else
			this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap "<< this->name << " can't take anymore damage..." << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy left!" << std::endl;
		return ;
	}
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " seems out of order..." << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " hit points!" << std::endl;
}

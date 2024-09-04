#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap() {
	FragTrap::hitPoints = 100;
	FragTrap::energyPoints = 100;
	FragTrap::attackDamage = 30;
	std::cout << "FragTrap producted!" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name) {
	FragTrap::hitPoints = 100;
	FragTrap::energyPoints = 100;
	FragTrap::attackDamage = 30;
	std::cout << "FragTrap " << name << " producted!" << std::endl;
}

FragTrap::FragTrap( FragTrap const &fragTrap ): ClapTrap(fragTrap) {
	std::cout << "FragTrap " << fragTrap.name << " copied!" << std::endl;
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
	std::cout << "FragTrap " << this->name << " annihilated!" << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->name << " accepts a high five!" << std::endl;
}

void	FragTrap::attack( const std::string target ) {
	if (this->energyPoints == 0) {
		std::cout << "ScavTrap " << this->name << " has no more energy!" << std::endl;
		return ;
	}
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " seems to be broken..." << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " strikes " << target << ", doing ";
	std::cout << this->attackDamage << " points of damage!" << std::endl;
}

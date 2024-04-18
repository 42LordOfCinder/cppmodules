#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap	michelle("michelle");
	michelle.attack("Jean-Claude");
	michelle.attack("Jean-Claude");
	michelle.takeDamage(5);
	michelle.attack("Christian");
	michelle.takeDamage(4);
	michelle.beRepaired(6);
	michelle.beRepaired(3);
	michelle.attack("Jean-Claude");
	michelle.attack("Christian");
	michelle.takeDamage(6);
	michelle.beRepaired(3);
	michelle.attack("Jean-Claude");
	michelle.attack("Christian");
	michelle.attack("Christian");
	michelle.takeDamage(1000);
	michelle.attack("Jean-Claude");
	michelle.takeDamage(10);
	ClapTrap	arthur("arthur");
	arthur.takeDamage(9);
	arthur.attack("Christian");
	arthur.takeDamage(2);
	arthur.attack("Christian");
	return 0;
}

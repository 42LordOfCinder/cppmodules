#include "FragTrap.hpp"
#include <iostream>

int	main( void ) {
	FragTrap	ronald("Ronald");
	ronald.attack("McDonald");
	ronald.beRepaired(3);
	ronald.takeDamage(10);
	ronald.highFivesGuys();
	ronald.takeDamage(100000);
	ronald.attack("McDonald");
	return 0;
}

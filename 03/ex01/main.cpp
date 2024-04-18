#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap	jonathan("Jonathan");
	jonathan.attack("Remy");
	jonathan.takeDamage(2);
	jonathan.beRepaired(3);
	jonathan.takeDamage(200);
	jonathan.attack("Remy");
	return 0;
}

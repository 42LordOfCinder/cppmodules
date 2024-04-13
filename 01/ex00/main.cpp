#include "Zombie.hpp"

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

int	main(void) {
	Zombie	*zomb = newZombie("Ping");
	zomb->announce();
	randomChump("Pong");
	delete zomb;
	return 0;
}

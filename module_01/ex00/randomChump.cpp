#include "Zombie.h"

void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
}

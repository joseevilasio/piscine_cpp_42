#include "Zombie.h"

int	main(void)
{
	Zombie* one = newZombie("Morty");
	one->announce();
	delete one;
	randomChump("Rick");
	return (0);
}
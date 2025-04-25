#include "Zombie.h"

int	main(void)
{
	Zombie* horde = zombieHorde(10, "Rick");
	for (int i = 0; i < 10; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
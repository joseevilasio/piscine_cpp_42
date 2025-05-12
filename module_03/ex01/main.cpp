#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
		ScavTrap marvin("Marvin");
		ClapTrap* other = &marvin;
		ClapTrap* again = new ScavTrap("Marvin");

		//marvin.display(); //debug
	
		marvin.takeDemage(2);
		marvin.attack("Jim");

		std::cout << std::endl;

		other->attack("other -> Jim");
		again->attack("again -> Jim");

		std::cout << std::endl;

		marvin.beRepaired(2);
		marvin.guardGate();

		//marvin.display(); //debug
	}

	std::cout << "\n\n ---------------- \n\n";

	{
		ClapTrap jim("Jim");

		//jim.display(); //debug
	
		jim.attack("Marvin");
		jim.beRepaired(2);
		jim.takeDemage(2);

		//jim.display(); //debug
	}

	return (0);
}

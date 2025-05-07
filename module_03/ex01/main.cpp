#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
		ScavTrap marvin("Marvin");

		//marvin.display(); //debug
	
		marvin.takeDemage(2);
		marvin.attack("Jim");
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

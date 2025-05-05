#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
		ScavTrap marvin("Marvin");
	
		marvin.takeDemage(2);
		marvin.attack("Jim");
		marvin.beRepaired(2);
		marvin.guardGate();
	}

	std::cout << "\n\n ---------------- \n\n";

	{
		ClapTrap jim("Jim");
	
		jim.attack("Marvin");
		jim.beRepaired(2);
		jim.takeDemage(2);
	}

	return (0);
}

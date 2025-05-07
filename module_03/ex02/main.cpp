#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

	std::cout << "\n\n ---------------- \n\n";

	{
		FragTrap other("Other");

		//other.display();
	
		other.attack("Marvin");
		other.beRepaired(2);
		other.takeDemage(2);
		other.highFivesGuys();

		//other.display();
	}

	return (0);
}

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	{
		ClapTrap jim("Jim");

		//jim.display(); //debug
		
		jim.attack("Rick");
		jim.takeDemage(2);
		jim.beRepaired(2);

		//jim.display(); //debug
	}

	{
		ClapTrap rick("Rick");

		//rick.display(); //debug

		rick.takeDemage(2);
		rick.attack("Jim");
		rick.beRepaired(2);

		//rick.display(); //debug
	}

	return (0);
}

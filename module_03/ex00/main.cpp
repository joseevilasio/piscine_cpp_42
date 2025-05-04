#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap jim("Jim");
	ClapTrap rick("Rick");

	jim.attack("Rick");
	rick.takeDemage(2);

	rick.attack("Jim");
	jim.takeDemage(2);
	
	rick.beRepaired(2);
	jim.beRepaired(2);

	return (0);
}

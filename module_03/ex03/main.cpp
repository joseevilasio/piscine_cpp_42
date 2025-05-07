#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{

	/*    ClapTrap
	      /     \
	 FragTrap  ScavTrap
	      \     /
	    DiamondTrap
	*/

	{
		DiamondTrap marvin("Marvin");

		//marvin.display(); //debug
	
		marvin.attack("Jim");
		marvin.whoAmI();

		//marvin.display(); //debug
	}

	return (0);
}

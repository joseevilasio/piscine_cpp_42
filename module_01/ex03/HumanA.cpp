#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const name, Weapon& weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << "<" << _name << "> " << "attacks with their <"
		<< _weapon.getType() << ">" << std::endl;
}

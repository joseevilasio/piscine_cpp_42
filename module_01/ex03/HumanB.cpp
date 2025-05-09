#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

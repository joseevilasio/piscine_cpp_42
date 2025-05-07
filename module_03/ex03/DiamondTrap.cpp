#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoint = rhs._energyPoint;
		_attackDemage = rhs._attackDemage;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
	: ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap: " << _name
		<< " ClapTrap: " << ClapTrap::_name << std::endl;
}

/* void	DiamondTrap::display(void)
{
	std::cout << "\n --- Display DiamondTrap ---" << std::endl
		<< "_name: " << _name << std::endl
		<< "_hitPoints: " << _hitPoints << std::endl
		<< "_energyPoints: " <<	_energyPoint << std::endl
		<< "_attackDemage: " << _attackDemage << std::endl
		<< " --- " << std::endl;
} */

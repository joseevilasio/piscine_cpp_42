#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoint = 100;
	_attackDemage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoint = rhs._energyPoint;
		_attackDemage = rhs._attackDemage;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests high fives!" << std::endl;
}

/* void	FragTrap::display(void)
{
	std::cout << "\n --- Display FragTrap ---" << std::endl
		<< "_name: " << _name << std::endl
		<< "_hitPoints: " << _hitPoints << std::endl
		<< "_energyPoints: " <<	_energyPoint << std::endl
		<< "_attackDemage: " << _attackDemage << std::endl
		<< " --- " << std::endl;
} */
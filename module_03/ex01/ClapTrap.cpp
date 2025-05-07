#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoint(10), _attackDemage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoint = rhs._energyPoint;
		_attackDemage = rhs._attackDemage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoint > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDemage << " points of damage!" << std::endl;
		_energyPoint--;
	}
}

void	ClapTrap::takeDemage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " had " << amount
		<< " damage! " << std::endl;
		if (_hitPoints < amount)
			_hitPoints = 0;
		else
			_hitPoints-=amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repaired " << amount
		<< " hit points!" << std::endl;
		_energyPoint--;
		_hitPoints+=amount;
	}
}

/* void	ClapTrap::display(void)
{
	std::cout << "\n --- Display ClapTrap ---" << std::endl
		<< "_name: " << _name << std::endl
		<< "_hitPoints: " << _hitPoints << std::endl
		<< "_energyPoints: " <<	_energyPoint << std::endl
		<< "_attackDemage: " << _attackDemage << std::endl
		<< " --- " << std::endl;
} */

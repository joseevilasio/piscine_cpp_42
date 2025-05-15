#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name)
{
	std::cout << "[Character] Default constructor called" << std::endl;
}

Character::Character(const Character& rhs)
{
	std::cout << "[Character] Copy constructor called" << std::endl;
	*this = rhs;
}
Character& Character::operator=(const Character& rhs)
{
	std::cout << "[Character] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			_slots[i] = rhs._slots[i];
		}
	}
	return (*this);
}

Character::~Character(void)
{
	std::cout << "[Character] Destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}


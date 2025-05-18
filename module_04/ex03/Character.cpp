#include "Character.hpp"
#include <iostream>

Character::Character(std::string name)
	: _name(name), _unequippedCount(0), _unequippedCapacity(4)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_unequipped = new AMateria*[_unequippedCapacity];
	std::cout << "[Character] Default constructor called" << std::endl;
}

Character::Character(const Character& rhs)
	: _name(rhs._name), _unequippedCount(rhs._unequippedCount),
	_unequippedCapacity(rhs._unequippedCapacity)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;

	_unequipped = new AMateria*[_unequippedCapacity];
	for (int i = 0; i < _unequippedCount; ++i)
		_unequipped[i] = rhs._unequipped[i]->clone();

	std::cout << "[Character] Copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& rhs)
{	
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
		}

		for (int i = 0; i < _unequippedCount; i++)
			delete _unequipped[i];
		delete[] _unequipped;

		_name = rhs._name;
		_unequippedCount = rhs._unequippedCount;
		_unequippedCapacity = rhs._unequippedCapacity;

		_unequipped = new AMateria*[_unequippedCapacity];
		for (int i = 0; i < _unequippedCapacity; i++)
			_unequipped[i] = rhs._unequipped[i]->clone();
	}
	std::cout << "[Character] Copy assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < _unequippedCount; i++)
		delete _unequipped[i];
	delete[] _unequipped;
	std::cout << "[Character] Destructor called" << std::endl;
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
		if (i == 3 && _inventory[i] != NULL)
			std::cout << "[Character] equip() -> FULL slots" << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
	{
		std::cout << "[Character] unequip() -> Invalid index or Empty slot" << std::endl;
		return ;
	}
	storeUnequipped(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}
	else
	{
		std::cout << "[Character] use() -> Invalid index or Empty slot" << std::endl;
	}
}

void Character::storeUnequipped(AMateria* m)
{
	if (_unequippedCount >= _unequippedCapacity) {
		int newCapacity = _unequippedCapacity * 2;
		AMateria** newArray = new AMateria*[newCapacity];

		for (int i = 0; i < _unequippedCount; i++)
			newArray[i] = _unequipped[i];

		delete[] _unequipped;
		_unequipped = newArray;
		_unequippedCapacity = newCapacity;
	}

	_unequipped[_unequippedCount++] = m;
}



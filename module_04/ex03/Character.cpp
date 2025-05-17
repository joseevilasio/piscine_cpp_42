#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : _name(name), _trashCount(0)
{
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	for (int i = 0; i < 100; i++)
		_trash[i] = NULL;
	std::cout << "[Character] Default constructor called" << std::endl;
}

Character::Character(const Character& rhs) : _name(rhs._name), _trashCount(0)
{
	std::cout << "[Character] Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs._slots[i])
			_slots[i] = rhs._slots[i]->clone();
		else
			_slots[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
		_trash[i] = NULL;
}

Character& Character::operator=(const Character& rhs)
{
	std::cout << "[Character] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _slots[i];
			_slots[i] = NULL;
		}
		for (int i = 0; i < _trashCount; i++)
		{
			delete _trash[i];
			_trash[i] = NULL;
		}
		_trashCount = 0;
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (rhs._slots[i])
				_slots[i] = rhs._slots[i]->clone();
			else
				_slots[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _slots[i];
	for (int i = 0; i < _trashCount; i++)
		delete _trash[i];
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
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			return ;
		}
		if (i == 3 && _slots[i] != NULL) //debug
			std::cout << "[Character] equip() -> FULL slots" << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _slots[idx] != NULL)
	{
		if (_trashCount < 100)
			_trash[_trashCount++] = _slots[idx];
		else
		{
			std::cout << "[Character] unequip() -> FULL trash" << std::endl; //debug
			return ;
		}
		_slots[idx] = NULL;
	}
	else //debug
	{
		std::cout << "[Character] unequip() -> Invalid index or Empty slot" << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _slots[idx] != NULL)
	{
		_slots[idx]->use(target);
	}
	else //debug
	{
		std::cout << "[Character] use() -> Invalid index or Empty slot" << std::endl;
	}
}


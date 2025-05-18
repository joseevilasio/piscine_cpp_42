#include "MateriaSource.hpp"
#include "Ice.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << "[MateriaSource] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] Copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (rhs._templates[i])
			_templates[i] = rhs._templates[i];
		else
			_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			_templates[i] = (rhs._templates[i]) ? rhs._templates[i]->clone() : NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		delete _templates[i];
	std::cout << "[MateriaSource] Destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for(int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = materia->clone();
			delete materia;
			return ;
		}
		if (i == 3 && _templates[i] != NULL)
			std::cout << "[Character] equip() -> FULL slots" << std::endl;
	}
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if (_templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	std::cout << "Unknown materia: " << type << std::endl;
	return (0);
}

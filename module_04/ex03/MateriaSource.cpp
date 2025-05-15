#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	std::cout << "[MateriaSource] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] Copy constructor called" << std::endl;
	*this = rhs;
}
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "[MateriaSource] Destructor called" << std::endl;
}

void learnMateria(AMateria*);
{
	;
}

AMateria* createMateria(std::string const & type)
{

}
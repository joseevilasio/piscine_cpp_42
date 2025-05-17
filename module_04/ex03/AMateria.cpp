#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
	std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "[AMateria] Parameter constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& rhs)
{
	std::cout << "[AMateria] Copy constructor called" << std::endl;
	*this = rhs;
}
AMateria& AMateria::operator=(const AMateria& rhs)
{
	std::cout << "[AMateria] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "[AMateria] Destructor called" << std::endl;
}

std::string const &	AMateria::getType() const
{
	return(_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] use() nothing happens with " << target.getName() << std::endl;
}

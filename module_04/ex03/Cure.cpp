#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs)
{
	std::cout << "[Cure] Copy constructor called" << std::endl;
	*this = rhs;
}
Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << "[Cure] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "[Cure] Destructor called" << std::endl;
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}

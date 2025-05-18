#include "Fire.hpp"
#include <iostream>

Fire::Fire(void) : AMateria("Fire")
{
	std::cout << "[Fire] Default constructor called" << std::endl;
}

Fire::Fire(const Fire& rhs) : AMateria(rhs)
{
	std::cout << "[Fire] Copy constructor called" << std::endl;
	*this = rhs;
}
Fire& Fire::operator=(const Fire& rhs)
{
	std::cout << "[Fire] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Fire::~Fire(void)
{
	std::cout << "[Fire] Destructor called" << std::endl;
}

Fire*	Fire::clone() const
{
	return (new Fire(*this));
}

void	Fire::use(ICharacter& target)
{
	std::cout << "* shoots an fire bolt at " << target.getName() << " *" << std::endl;
}

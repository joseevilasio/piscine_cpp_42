#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "[Ice] Default constructor called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs)
{
	std::cout << "[Ice] Copy constructor called" << std::endl;
	*this = rhs;
}
Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << "[Ice] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "[Ice] Destructor called" << std::endl;
}

Ice*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

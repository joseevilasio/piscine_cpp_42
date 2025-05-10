#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Undefined")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

const std::string& WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Undefined sound!" << std::endl;
}
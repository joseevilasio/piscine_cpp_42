#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Undefined")
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

AAnimal::AAnimal(const AAnimal& rhs)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

const std::string& AAnimal::getType(void) const
{
	return (_type);
}

/* void	AAnimal::makeSound(void) const
{
	std::cout << "Undefined sound!" << std::endl;
} */
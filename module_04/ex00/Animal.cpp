#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Undefined")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = rhs;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Undefined sound!" << std::endl;
}
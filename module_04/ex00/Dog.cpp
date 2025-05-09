#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal(), _type("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Dog::Dog(const Dog& rhs) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = rhs;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

const std::string& Dog::getType(void) const
{
	return (_type);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << ": Woof!!" << std::endl;
}

#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal(), _type("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Cat::Cat(const Cat& rhs) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = rhs;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

const std::string& Cat::getType(void) const
{
	return (_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miau!!" << std::endl;
}

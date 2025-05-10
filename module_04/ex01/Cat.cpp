#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : brain(new Brain())
{
	_type = "Cat";
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

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << _type << ": Meow!!" << std::endl;
}

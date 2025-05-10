#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	_brain = new Brain(*rhs._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << _type << ": Meow!!" << std::endl;
}

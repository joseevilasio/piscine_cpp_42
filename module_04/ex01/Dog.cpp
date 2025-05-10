#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_brain = new Brain(*rhs._brain);
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << _type << ": Woof!!" << std::endl;
}

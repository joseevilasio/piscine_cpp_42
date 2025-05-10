#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	(void)rhs;
	std::cout << "Brain Copy assignment operator called" << std::endl;
	// if (this != &rhs)
	// {
	// 	_type = rhs._type;
	// }
	return (*this);
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = rhs;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

// const std::string& Brain::getType(void) const
// {
// 	return (_type);
// }

// void	Brain::makeSound(void) const
// {
// 	std::cout << "Undefined sound!" << std::endl;
// }
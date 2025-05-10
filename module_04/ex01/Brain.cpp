#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = rhs._ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

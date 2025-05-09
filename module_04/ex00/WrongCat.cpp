#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal(), _type("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal()
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

const std::string& WrongCat::getType(void) const
{
	return (_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << _type << ": Meow!!" << std::endl;
}

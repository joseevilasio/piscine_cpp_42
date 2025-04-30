#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed(fixed);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
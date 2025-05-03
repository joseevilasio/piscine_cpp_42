#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = integer << _fractionalBits;
}

Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floating * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_rawBits = rhs._rawBits;
	}
	return (*this);
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.toFloat();
	return (os);
}

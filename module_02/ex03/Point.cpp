#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	//std::cout << "Paramenter constructor called" << std::endl;
}

Point& Point::operator=(const Point& rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		(Fixed) this->_x = rhs._x;
		(Fixed) this->_y = rhs._y;
	}
	return (*this);
}

Point::Point(const Point& rhs)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Point::~Point(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getPointX(void) const
{
	return (_x);
}

Fixed	Point::getPointY(void) const
{
	return (_y);
}

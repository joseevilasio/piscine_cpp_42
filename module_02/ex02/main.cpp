#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	//std::cout << Fixed::max( a, b ) << std::endl;

	Fixed x(5);
	Fixed z(5);

	std::cout << "x + z = " << (x + z) << std::endl;
	std::cout << "x - z = " << (x - z) << std::endl;
	std::cout << "x * z = " << (x * z) << std::endl;
	std::cout << "x / z = " << (x / z) << std::endl;
	
	return (0);
}

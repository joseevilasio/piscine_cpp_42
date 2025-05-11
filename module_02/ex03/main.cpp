#include "bsp.h"
#include <iostream>

int	main(void)
{
	Point a(0.0, 0.0);
	Point b(4.0, 0.0);
	Point c(0.0, 4.0);

	Point x(0.0, 4.0); //in
	Point z(0.0, 5.0); //out

	bsp(a, b, c, x);
	std::cout << std::endl;
	bsp(a, b, c, z);

	return (0);
}

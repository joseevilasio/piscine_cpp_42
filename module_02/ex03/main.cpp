#include "bsp.h"
#include <iostream>

int	main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 3);
	Point x(10, 10);

	bsp(a, b, c, x);
	return (0);
}

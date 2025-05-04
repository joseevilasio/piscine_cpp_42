#include "bsp.h"
#include <iostream>

int	main(void)
{
	Point a(100, 100);
	Point b(400, 100);
	Point c(100, 300);
	Point x(100, 100);

	bsp(a, b, c, x);

	return (0);
}

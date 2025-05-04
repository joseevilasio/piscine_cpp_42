#include "bsp.h"
#include <iostream>

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 3.0f);
	Point x(10.0f, 10.0f);

	bsp(a, b, c, x);

	return (0);
}

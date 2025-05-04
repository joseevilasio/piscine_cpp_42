#include "bsp.h"

static	Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed div(2);
	Fixed area = ( a.getPointX() * ( b.getPointY() - c.getPointY() ) +
					b.getPointX() * ( c.getPointY() - a.getPointY() ) +
					c.getPointX() * ( a.getPointY() - b.getPointY() )) / div;
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = area(a, b, c);
	Fixed t1 = area(point, b, c);
	Fixed t2 = area(a, point, c);
	Fixed t3 = area(a, b, point);
	Fixed sum = (t1 + t2 + t3);

	std::cout << "Total area of the triangle [a, b, c] -> " << totalArea << std::endl;
	std::cout << "Three news triangles generated:" << std::endl;
	std::cout << "- Total area of T1 [p, b, c] -> " << t1 << std::endl;
	std::cout << "- Total area of T2 [a, p, c] -> " << t2 << std::endl;
	std::cout << "- Total area of T3 [a, b, p] -> " << t3 << std::endl;
	std::cout << "   Sum of the area triangles -> " << sum << std::endl;

	if (totalArea == sum)
	{
		std::cout << "The point is inside the triangle." << std::endl;
		return (true);
	}
	std::cout << "The point is not inside the triangle." << std::endl;
	return (false);
}

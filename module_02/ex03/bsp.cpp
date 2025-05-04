#include "bsp.h"

static	Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed div(2);
	Fixed t1 = a.getPointX() * ( b.getPointY() - c.getPointY());
	Fixed t2 = b.getPointX() * ( c.getPointY() - a.getPointY());
	Fixed t3 = c.getPointX() * ( a.getPointY() - b.getPointY() );
	// Fixed area = ( a.getPointX() * ( b.getPointY() - c.getPointY() ) +
	// 				b.getPointX() * ( c.getPointY() - a.getPointY() ) +
	// 				c.getPointX() * ( a.getPointY() - b.getPointY() )) / div;
	Fixed area = (t1 + t2 + t3) / div;
	if (area < Fixed(0))
		area = area * Fixed(-1);
	std::cout << "t1: " << t1.toFloat() << std::endl;
	std::cout << "t2: " << t2.toFloat() << std::endl;
	std::cout << "t3: " << t3.toFloat() << std::endl;
	std::cout << "area: " << area.toFloat() << std::endl;
	std::cout << a.getPointX() << std::endl;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = area(a, b, c);
	Fixed t1 = area(point, b, c);
	Fixed t2 = area(a, point, c);
	Fixed t3 = area(a, b, point);

	std::cout << "Total area of the triangle [a, b, c] -> " << totalArea << std::endl;
	std::cout << "Three news triangles generated:" << std::endl;
	std::cout << "- Total area of T1 [p, b, c] -> " << t1 << std::endl;
	std::cout << "- Total area of T2 [a, p, c] -> " << t2 << std::endl;
	std::cout << "- Total area of T3 [a, b, p] -> " << t3 << std::endl;
	return (true);
}

// double area = (p1.x * (p2.y - p3.y) +
// p2.x * (p3.y - p1.y) +
// p3.x * (p1.y - p2.y)) / 2.0;

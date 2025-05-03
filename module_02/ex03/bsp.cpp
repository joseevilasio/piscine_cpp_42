#include "bsp.h"

static	Fixed	areaCalculate(Point const a, Point const b, Point const c)
{
	Fixed div(2.0f);
	Fixed area = ( a.getPointX() * ( b.getPointY() - c.getPointY() ) +
					b.getPointX() * ( c.getPointY() - a.getPointY() ) +
					c.getPointX() * ( a.getPointY() - b.getPointY() )) / div;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	(void) point;
	std::cout << areaCalculate(a, b, c).toFloat() << std::endl;
	return (true);
}

// double area = (p1.x * (p2.y - p3.y) +
// p2.x * (p3.y - p1.y) +
// p3.x * (p1.y - p2.y)) / 2.0;
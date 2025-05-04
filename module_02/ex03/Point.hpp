#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& rhs);
		Point& operator=(const Point& rhs);
		~Point(void);

		Fixed	getPointX(void) const;
		Fixed	getPointY(void) const;
};

#endif //POINT_HPP
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static int const	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed& operator=(const Fixed& rhs);
		Fixed(const Fixed& rhs);
		~Fixed(void);

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif //FIXED_HPP
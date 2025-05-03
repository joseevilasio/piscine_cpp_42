#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
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

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& lhs, Fixed& rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif //FIXED_HPP
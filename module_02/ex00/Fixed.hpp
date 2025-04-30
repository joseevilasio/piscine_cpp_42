#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int	_fixedPoint;
		static int const _fractionalBits;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		~Fixed(void);
		Fixed & operator = (const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP
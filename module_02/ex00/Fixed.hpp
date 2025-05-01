#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static int const	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed& operator=(const Fixed& rhs);
		Fixed(const Fixed& rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP
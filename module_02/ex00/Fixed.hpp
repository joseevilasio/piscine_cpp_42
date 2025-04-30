#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int	fixedPoint;
		static int const fractionalBits;

	public:
		Fixed(/* args */);
		~Fixed();
};

#endif //FIXED_HPP
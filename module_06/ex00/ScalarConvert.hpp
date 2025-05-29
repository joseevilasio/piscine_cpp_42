#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <iostream>

class ScalarConvert
{
	private:
		ScalarConvert(void);
		ScalarConvert&	operator=(const ScalarConvert& rhs);
		ScalarConvert(const ScalarConvert& rhs);
		~ScalarConvert(void);

		static void	convertFromChar(char c);
		static void	convertFromInt(int i);
		static void	convertFromFloat(float f);
		static void	convertFromDouble(double d);

		static bool	isChar(const std::string& src);
		static bool	isInt(const std::string& src);
		static bool	isFloat(const std::string& src);
		static bool	isDouble(const std::string& src);

	public:
		static void	convert(const std::string& src);
};

#endif //SCALAR_CONVERT_HPP
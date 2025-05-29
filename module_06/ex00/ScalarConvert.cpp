#include "ScalarConvert.hpp"
#include <exception>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cctype>
#include <cmath>

ScalarConvert::ScalarConvert(void) {}

ScalarConvert&	ScalarConvert::operator=(const ScalarConvert& rhs)
{
	if (this != &rhs)
	{
		ScalarConvert::operator=(rhs);
	}
	return (*this);
}

ScalarConvert::ScalarConvert(const ScalarConvert& rhs) {*this=rhs;}

ScalarConvert::~ScalarConvert(void) {}

void	ScalarConvert::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void	ScalarConvert::convertFromInt(int i)
{
	if (i >= 0 && i <= 127)
	{
		if (std::isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
	else
		std::cout << "char: impossible\n";
	std::cout << "int: " << i << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void	ScalarConvert::convertFromFloat(float f)
{
	if (std::isnan(f) || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	
	if (std::isnan(f) || f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void	ScalarConvert::convertFromDouble(double d)
{
	if (std::isnan(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	
	if (std::isnan(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	std::cout << std::fixed << std::setprecision(1);

	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << static_cast<float>(d) << "f\n";
	
	std::cout << "double: " << d << "\n";
}


bool	ScalarConvert::isChar(const std::string& src)
{
	if (src.length() == 3 && src[0] == '\'' && src[2] == '\'')
		return (true);
	return (false);
}

bool	ScalarConvert::isInt(const std::string& src)
{
	char* end;
	errno = 0;
	long num = std::strtol(src.c_str(), &end, 10);

	if (*end == '\0' && errno == 0 && num >= INT_MIN && num <= INT_MAX)
		return (true);
	return (false);
}

bool	ScalarConvert::isFloat(const std::string& src)
{
	if (src == "nanf" || src == "+inff" || src == "-inff")
		return (true);
	if (src.find('f') == std::string::npos)
		return (false);
	char *end;
	std::strtof(src.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		return (false);
	return (true);
}

bool	ScalarConvert::isDouble(const std::string& src)
{
	if (src == "nan" || src == "+inf" || src == "-inf")
		return (true);
	char *end;
	std::strtod(src.c_str(), &end);
	if (*end == '\0')
		return (false);
	return (true);
}

void	ScalarConvert::convert(const std::string& src)
{
	if (isChar(src))
		convertFromChar(src[1]);
	else if (isInt(src))
	{
		int i = std::atoi(src.c_str());
		convertFromInt(i);
	}
	else if (isFloat(src))
	{
		float f = std::strtof(src.c_str(), NULL);
		convertFromFloat(f);
	}
	else if (isDouble(src))
	{
		double d = std::strtod(src.c_str(), NULL);
		convertFromDouble(d);
	}
	else
		throw std::invalid_argument("Invalid argument");
}

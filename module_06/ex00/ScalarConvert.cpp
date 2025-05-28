#include "ScalarConvert.hpp"

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

void	ScalarConvert::convert(const std::string& src)
{
	static_cast()
}
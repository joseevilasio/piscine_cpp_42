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

	public:
		static void	convert(const std::string& src);
};

#endif //SCALAR_CONVERT_HPP
#include "ScalarConvert.hpp"
#include <cstdlib>

int	main(int argc, char** argv)
{
	if (argc != 2)
		return (1);
	try
	{
		ScalarConvert::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}	
	return (0);
}

// int main(void)
// {
// 	{
// 		int a = 42;
// 		double b = a; //implicit type conversion
	
// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}

// 	{
// 		int a = 10;
// 		double b = (double) a;
	
// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}

// 	{
// 		double a = 100.2;
// 		int b = a;
	
// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}

// 	{
// 		std::string a = "100";
// 		int b = (int) std::atoi(a.c_str());
	
// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}

// 	{
// 		double a = 99999999999.9;
// 		int b = static_cast<int>(a);
	
// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}

// 	return (0);
// }
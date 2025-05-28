#include "ScalarConvert.hpp"

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
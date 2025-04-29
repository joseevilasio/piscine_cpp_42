#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (1);
	}

	std::string level(argv[1]);
	Harl harl;

	harl.complain(level);
	return (0);
}

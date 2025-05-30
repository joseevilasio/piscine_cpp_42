#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::srand(std::time(0));

	{
		std::cout << "\n Test 01 - Pointer\n";
		Base* undefined = generate();
		std::cout << "Pointer identification: ";
		identify(undefined);
		delete undefined;
	}

	{
		std::cout << "\n Test 02 - Pointer\n";
		Base* undefined = generate();
		std::cout << "Pointer identification: ";
		identify(undefined);
		delete undefined;
	}

	{
		std::cout << "\n Test 03 - Reference\n";
		Base* undefined = generate();
		std::cout << "Reference identification: ";
		identify(*undefined);
		delete undefined;
	}

	{
		std::cout << "\n Test 04 - Reference\n";
		Base* undefined = generate();
		std::cout << "Reference identification: ";
		identify(*undefined);
		delete undefined;
	}

	return (0);
}
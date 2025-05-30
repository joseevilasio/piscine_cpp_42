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

	// {
	// 	std::cout << "\n Test 05 - Const cast\n";
	// 	const std::string protected_ = "Unchanging";

	// 	std::string& ref = const_cast<std::string&>(protected_);
	// 	//std::string& ref = protected_;

	// 	ref = "const cast";

	// 	std::cout << "Before: " << protected_ << std::endl;
	// 	std::cout << "After: " << ref << std::endl;
	// }

	return (0);
}
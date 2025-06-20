#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	(void)argv;

	if (argc < 2)
	{
		std::cout << "Error\n";
	}

	RPN polish;

	polish.insert(10);
	polish.remove();
	// polish.remove();

	return (0);
}
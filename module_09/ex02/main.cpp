#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Invalid Argument" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe p(argc - 1, argv);
		p.info();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat("Alice", 0);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		Bureaucrat bob("Bob", 100);
		std::cout << bob;
	}

	{
		try
		{
			Bureaucrat marvin("Marvin", 150);
			std::cout << marvin;
			marvin.decrement();
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		try
		{
			Bureaucrat marvin("Marvin", 1);
			std::cout << marvin;
			marvin.increment();
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return (0);
}
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
		try
		{
			Bureaucrat bob("Bob", 100);
			std::cout << bob;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
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
			std::cout << marvin;
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
			marvin.decrement();
			std::cout << marvin;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return (0);
}
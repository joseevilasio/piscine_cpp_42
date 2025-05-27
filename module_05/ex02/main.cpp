#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		try
		{
			ShrubberyCreationForm a1("Alice");
			std::cout << a1;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	// {
	// 	AForm contract("contract", 75, 10);
	// 	Bureaucrat bob("Bob", 76);
	// 	Bureaucrat rick("Rick", 74);

	// 	bob.signForm(contract);
	// 	rick.signForm(contract);

	// 	std::cout << contract;
	// }

	return (0);
}
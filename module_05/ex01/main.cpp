#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Form("request", 0, 10);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		Form contract("contract", 75, 10);
		Bureaucrat bob("Bob", 76);
		Bureaucrat rick("Rick", 74);
		Bureaucrat marvin("Marvin", 74);

		bob.signForm(contract);
		rick.signForm(contract);
		marvin.signForm(contract);

		std::cout << contract;
	}

	return (0);
}
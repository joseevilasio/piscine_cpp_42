#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	{
		std::cout << " -- Intern -- OK --" << std::endl;
		try
		{
			Intern someRandomIntern;
			AForm* rrf;

			Bureaucrat bob("Bob", 10);

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");

			bob.signForm(*rrf);
			bob.executeForm(*rrf);

			delete rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

	}

	{
		std::cout << " -- Intern -- Error --" << std::endl;
		try
		{
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("otherform request", "Bender");
			(void) rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
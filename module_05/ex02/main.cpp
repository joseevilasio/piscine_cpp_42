#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		Bureaucrat bob("Bob", 10);
		ShrubberyCreationForm home("home");
			
		std::cout << " -- ShrubberyCreationForm -- OK --" << std::endl;
		std::cout << home;

		bob.signForm(home);
		bob.executeForm(home);

		std::cout << std::endl;
	}

	{
		Bureaucrat rick("Rick", 10);
		RobotomyRequestForm washingDishes("washing dishes");
		
		std::cout << " -- RobotomyRequestForm -- OK --" << std::endl;
		std::cout << washingDishes;

		rick.signForm(washingDishes);
		rick.executeForm(washingDishes);

		std::cout << std::endl;
	}

	{
		Bureaucrat rick("Rick", 10);
		PresidentialPardonForm bob("bob");
		
		std::cout << " -- PresidentialPardonForm -- OK --" << std::endl;
		std::cout << bob;

		rick.signForm(bob);
		rick.executeForm(bob);

		std::cout << std::endl;
	}

	{
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm home("home");
		
		std::cout << " -- ShrubberyCreationForm -- Error --" << std::endl;
		std::cout << home;

		bob.signForm(home);
		bob.executeForm(home);

		std::cout << std::endl;
	}

	{
		Bureaucrat rick("Rick", 150);
		RobotomyRequestForm washingDishes("washing dishes");
		
		std::cout << " -- RobotomyRequestForm -- Error --" << std::endl;
		std::cout << washingDishes;

		rick.signForm(washingDishes);
		rick.executeForm(washingDishes);

		std::cout << std::endl;
	}

	{
		Bureaucrat rick("Rick", 150);
		PresidentialPardonForm bob("bob");
		
		std::cout << " -- PresidentialPardonForm -- Error --" << std::endl;
		std::cout << bob;

		rick.signForm(bob);
		rick.executeForm(bob);

		std::cout << std::endl;
	}

	{
		Bureaucrat rick("Rick", 150);
		PresidentialPardonForm bob("bob");
		
		std::cout << " -- PresidentialPardonForm -- Error --" << std::endl;
		std::cout << bob;

		//rick.signForm(bob);
		rick.executeForm(bob);
		
		std::cout << std::endl;
	}

	return (0);
}
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& rhs) {*this = rhs;}

Intern& Intern::operator=(const Intern& rhs)
{	
	(void) rhs;
	return (*this);
}

Intern::~Intern(void) {}

AForm*	Intern::makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* (Intern::*formFactory[3])(const std::string&) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	std::string _formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " <<  formName << std::endl;
			return ((this->*formFactory[i])(target));
		}
	}
	throw FormDoesNotExist();
}

const char*	Intern::FormDoesNotExist::what() const throw()
{
	return ("Intern: Form does not exist.");
}

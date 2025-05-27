#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm(rhs), _target(rhs._target)
{*this = rhs;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream output(filename.c_str());
	(void) bureaucrat;

	if (output.is_open())
	{
		std::string buffer = "ASCII trees\n";

		output << buffer;
		output.close();
	}
}

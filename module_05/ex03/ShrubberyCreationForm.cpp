#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm(rhs), _target(rhs._target) {}

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

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	
	if (!this->isSigned() || executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = _target + "_shrubbery";
	std::ofstream output(filename.c_str());

	if (output.is_open())
	{
		output << "         -_\n"
				<< "    /~~   ~~.\\ \n "
				<< " /~~         ~~\\ \n "
				<< "{               }\n "
				<< " \\  _-     -_  /\n "
				<< "   ~  \\ /./  ~\n"
				<< " - -   | | _- _ \n"
				<< "  _ -  | |   -_ \n"
				<< "      /./.\\ \n"
				<< "__" << _target << "__\n" ;

		output.close();
	}
}

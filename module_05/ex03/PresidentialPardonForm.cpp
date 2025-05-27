#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 25), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	: AForm(rhs), _target(rhs._target)
{*this = rhs;}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::cout << _target
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw GradeTooLowException();
}

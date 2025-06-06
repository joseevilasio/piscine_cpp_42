#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	: AForm(rhs), _target(rhs._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::cout << _target
		<< " has been robotomized successfully 50% of the time." << std::endl;
	}
	else
	{
		std::cout << "robotomy failed!" << std::endl;
		throw GradeTooLowException();
	}
}

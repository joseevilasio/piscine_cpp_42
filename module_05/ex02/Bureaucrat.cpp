#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) {*this = rhs;}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

const std::string&	Bureaucrat::getName(void) const {return (_name);}

int	Bureaucrat::getGrade(void) const {return (_grade);}

void	Bureaucrat::increment(void)
{
	if ((this->getGrade() - 1) < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrement(void)
{
	if ((this->getGrade() + 1) > 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return (os);
}

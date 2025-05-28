#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _isSigned(false) ,_gradeToSign(1), _gradeToExecute(1) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& rhs)
	: _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign),
		_gradeToExecute(rhs._gradeToExecute) {}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::~Form(void) {}

const std::string&	Form::getName(void) const {return (_name);}

bool	Form::isSigned(void) const {return (_isSigned);}

int	Form::getGradeToSign(void) const {return (_gradeToSign);}

int	Form::getGradeToExecute(void) const {return (_gradeToExecute);}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low");
}

const char*	Form::FormAlreadySigned::what() const throw()
{
	return ("Form: Form already signed");
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->isSigned())
		throw FormAlreadySigned();
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& rhs)
{
	os << "Form: " << rhs.getName() << " | "
		<< "Signed: " << (rhs.isSigned() ? "yes" : "no") << " | "
		<< "Grade to Sign: " << rhs.getGradeToSign() << " | "
		<< "Grade to Execute: " << rhs.getGradeToExecute()
		<< std::endl;
	return (os);
}

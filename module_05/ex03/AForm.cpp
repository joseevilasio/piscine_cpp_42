#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _isSigned(false) ,_gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& rhs)
	: _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign),
		_gradeToExecute(rhs._gradeToExecute)
{*this = rhs;}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

AForm::~AForm(void) {}

const std::string&	AForm::getName(void) const {return (_name);}

bool	AForm::isSigned(void) const {return (_isSigned);}

int	AForm::getGradeToSign(void) const {return (_gradeToSign);}

int	AForm::getGradeToExecute(void) const {return (_gradeToExecute);}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low");
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& rhs)
{
	os << "Form: " << rhs.getName() << " | "
		<< "Signed: " << (rhs.isSigned() ? "yes" : "no") << " | "
		<< "Grade to Sign: " << rhs.getGradeToSign() << " | "
		<< "Grade to Execute: " << rhs.getGradeToExecute()
		<< std::endl;
	return (os);
}

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _gradeSign(1), _gradeExecute(1) {}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
	: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLowException();
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& rhs)
	: _name(rhs._name), _signed(rhs._signed), _gradeSign(rhs._gradeSign),
		_gradeExecute(rhs._gradeExecute)
{*this = rhs;}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form(void) {}

const std::string&	Form::getName(void) const {return (_name);}

bool	Form::getSigned(void) const {return (_signed);}

int	Form::getGradeSign(void) const {return (_gradeSign);}

int	Form::getGradeExecute(void) const {return (_gradeExecute);}

// void	Form::increment(void)
// {
// 	if ((this->getGrade() - 1) < 1)
// 		throw GradeTooHighException();
// 	_grade--;
// }

// void	Form::decrement(void)
// {
// 	if ((this->getGrade() + 1) > 150)
// 		throw GradeTooLowException();
// 	_grade++;
// }

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void	Form::beSigned(Bureaucrat* bureaucrat)
{
	bureaucrat->signForm(this);
}

std::ostream&	operator<<(std::ostream& os, const Form& rhs)
{
	os << "Name: " << rhs.getName()
		<< "Signed: " << rhs.getSigned()
		<< "Grade Sign: " << rhs.getGradeSign()
		<< "Grade Execute: " << rhs.getGradeExecute()
		<< std::endl;
	return (os);
}

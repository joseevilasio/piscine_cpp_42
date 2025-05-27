#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm& rhs);
		AForm(const AForm& rhs);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif //A_FORM_HPP
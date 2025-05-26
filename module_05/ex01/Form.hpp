#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

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

		Form(void);
		Form(const std::string& name, int gradeSign, int gradeExecute);
		Form& operator=(const Form& rhs);
		Form(const Form& rhs);
		~Form(void);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;
		// void				increment(void);
		// void				decrement(void);
		void				beSigned(Bureaucrat* bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif //FORM_HPP
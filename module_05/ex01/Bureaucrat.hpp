#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

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

		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);
		void				signForm(Form& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif //BUREAUCRAT_HPP
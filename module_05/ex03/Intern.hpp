#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>

class AForm;

class Intern
{
	public:
		class FormDoesNotExist : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Intern(void);
		Intern& operator=(const Intern& rhs);
		Intern(const Intern& rhs);
		~Intern(void);

		AForm*	makePresidentialPardonForm(const std::string &target);
		AForm*	makeRobotomyRequestForm(const std::string &target);
		AForm*	makeShrubberyCreationForm(const std::string &target);
		AForm*	makeForm(const std::string& formName, const std::string& target);
};

#endif //INTERN_HPP
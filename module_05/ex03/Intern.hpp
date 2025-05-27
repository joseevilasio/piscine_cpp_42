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

		void	makeForm(const std::string& formName, const std::string& target) const;
};

#endif //INTERN_HPP
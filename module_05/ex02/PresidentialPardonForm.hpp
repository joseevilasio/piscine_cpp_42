#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm(void);

		void		execute(const Bureaucrat& executor) const;
};

#endif //PRESIDENTIAL_PARDON_FORM_HPP
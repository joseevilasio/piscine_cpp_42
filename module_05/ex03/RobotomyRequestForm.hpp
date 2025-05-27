#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm(void);

		void		execute(const Bureaucrat& executor) const;
};

#endif //ROBOTOMY_REQUEST_FORM_HPP
#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& rhs) {*this = rhs;}

Intern& Intern::operator=(const Intern& rhs)
{
	return (*this);
}

Intern::~Intern(void) {}

void	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::cout << "Intern creates <form>";
}

const char*	Intern::FormDoesNotExist::what() const throw()
{
	return ("Intern: Form does not exist.");
}

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>

void	Contact::setContact(const std::string& firstName,
			const std::string& lastName, const std::string& nickname,
			int phoneNumber, const std::string& darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (_nickname);
}

int	Contact::getPhoneNumber (void) const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

Contact::Contact(void) {};
Contact::~Contact(void) {};

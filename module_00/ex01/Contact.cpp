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

std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickname() const
{
	return (_nickname);
}

std::string Contact::getPhoneNumber () const
{
	std::ostringstream	oss;
	std::string			phoneNumber;

	oss << _phoneNumber;
	phoneNumber = oss.str();
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

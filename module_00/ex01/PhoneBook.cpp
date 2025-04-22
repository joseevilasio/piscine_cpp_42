#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

void	PhoneBook::addContact(const Contact& c)
{
	if (_count < MAX)
	{
		_contacts[_count] = c;
		_count++;
	}
	else
	{
		for (int i = 1; i < MAX; i++)
		{
			_contacts[i - 1] = _contacts[i];
		}
		_contacts[MAX - 1] = c;
	}
}

int	PhoneBook::getCount()
{
	return (_count);
}

static void	formmattedPrint(const std::string& str, int mode)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << std::setfill(' ') << std::right << str;
	if (mode == 1)
		std::cout << '|';
}

void	PhoneBook::displayAll()
{
	formmattedPrint("Index", 1);
	formmattedPrint("First Name", 1);
	formmattedPrint("Last Name", 1);
	formmattedPrint("Nickname", 0);
	std::cout << std::endl;
	for (int i = 1; i <= _count; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::string index = oss.str();
		formmattedPrint(index, 1);
		formmattedPrint(_contacts[i - 1].getFirstName(), 1);
		formmattedPrint(_contacts[i - 1].getLastName(), 1);
		formmattedPrint(_contacts[i - 1].getNickname(), 0);
		std::cout << std::endl;
	}
}

void	PhoneBook::displayContact(int id)
{
	std::ostringstream	oss;
	std::string			index;

	formmattedPrint("Index", 1);
	formmattedPrint("First Name", 1);
	formmattedPrint("Last Name", 1);
	formmattedPrint("Nickname", 1);
	formmattedPrint("Phone Number", 1);
	formmattedPrint("Darkest Secret", 0);
	std::cout << std::endl;
	oss << (id + 1);
	index = oss.str();
	formmattedPrint(index, 1);
	formmattedPrint(_contacts[id].getFirstName(), 1);
	formmattedPrint(_contacts[id].getLastName(), 1);
	formmattedPrint(_contacts[id].getNickname(), 1);
	formmattedPrint(_contacts[id].getPhoneNumber(), 1);
	formmattedPrint(_contacts[id].getDarkestSecret(), 0);
	std::cout << std::endl;
}

PhoneBook::PhoneBook(void) : _count(0) {};
PhoneBook::~PhoneBook(void){};
#include "awesomePhonebook.h"

static int	ensureValidInputNumber(const std::string& msg)
{
	std::string	line;
	int			input;

	while (true)
	{
		std::cout << msg;
		if (!std::getline(std::cin, line))
		{
			if (std::cin.eof())
			{
				std::cout << "Program closed\n";
				exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry, please try again!\n";
			continue ;
		}
		line = trim(line);
		if (!line.empty())
		{
			std::istringstream iss(line);
			if ((iss >> input) && (iss.eof())
				&& (input > 900000000 && input < 1000000000))
				break ;
		}
		std::cout << "Invalid entry, please try again!\n";
	}
	return (input);
}

static std::string	ensureValidInputString(const std::string& msg)
{
	std::string	input;

	while (true)
	{
		std::cout << msg;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cout << "Program closed\n";
				exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry, please try again!\n";
			continue ;
		}
		input = trim(input);
		if (!input.empty())
			break ;
		std::cout << "Invalid entry, please try again!\n";
	}
	return (input);
}

void	handleContact(PhoneBook& phonebook)
{
	Contact	c;

	std::cout << "[Add contact]\n";
	std::string	firstName = ensureValidInputString("First Name: ");
	std::string	lastName = ensureValidInputString("Last Name: ");
	std::string	nickname = ensureValidInputString("Nickname: ");
	int			phoneNumber = ensureValidInputNumber("Phone number: ");
	std::string	darkestSecret = ensureValidInputString("Darkest Secret: ");
	c.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phonebook.addContact(c);
	std::cout << "Contact added successfully!\n";
}

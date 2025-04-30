#include "awesomePhonebook.h"

static void	searchContact(PhoneBook& phonebook)
{
	std::string	line;
	int			input;

	std::cout << "Selecting a contact from the list [index]\n";
	while (true)
	{
		std::cout << "[index] > ";
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
				&& (input > 0 && input <= phonebook.getCount()))
				break ;
		}
		std::cout << "Invalid entry, please try again!\n";
	}
	phonebook.displayContact(input - 1);
}

void	handleSearch(PhoneBook& phonebook)
{
	phonebook.displayAll();
	if (phonebook.getCount() == 0)
		std::cout << "Empty list\n";
	else
		searchContact(phonebook);
}

#include "awesomePhonebook.h"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to the awesome phonebook \n";
	while (true)
	{
		prompt();
		std::getline(std::cin, command);
		if (command == "ADD")
			handleContact(phonebook);
		else if (command == "SEARCH")
			handleSearch(phonebook);
		else if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "Program closed\n";
			break ;
		}
	}
	return (0);
}

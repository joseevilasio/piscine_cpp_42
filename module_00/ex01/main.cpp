#include "awesome_phonebook.h"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	fillList(phonebook); //debug
	std::cout << "Welcome to the awesome phone book \n";
	std::cout << "Available commands: \n";
	std::cout << "[ADD] Save a new contact.\n";
	std::cout << "[SEARCH] Search by index.\n";
	std::cout << "[EXIT] Exit the program.\n";
	while (true)
	{
		std::cout << "> ";
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

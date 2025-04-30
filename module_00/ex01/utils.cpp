#include "awesomePhonebook.h"

std::string	trim(const std::string& str)
{
	size_t	start = 0;
	size_t	end = str.size();

	while (start < str.size() && (str[start] == ' ' || str[start] == '\n'
		|| str[start] == '\t' || str[start] == '\r'))
		++start;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\n'
		|| str[end - 1] == '\t' || str[end - 1] == '\r'))
		--end;
	return (str.substr(start, end - start));
}

void	prompt(void)
{
	std::cout << "Available commands: \n";
	std::cout << "↳ [ADD] Save a new contact. ";
	std::cout << " [SEARCH] Search by index. ";
	std::cout << " [EXIT] Exit the program.  \n";
	std::cout << "→  ";
}

/* void	fillList(PhoneBook& phonebook)
{
	//TEST
	Contact a, b, c, d, e, f, g;
	a.setContact("Joao", "Maria", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	b.setContact("Jose", "Neves", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	c.setContact("Maria", "Joao", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	d.setContact("Pedro", "Ribeiro", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	e.setContact("Mario", "Neves", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	f.setContact("Augusto", "Cesar", "The Machine", 999000111, "Um texto muito grande aqui com mais de 10");
	g.setContact("Rick", "Neves", "The Machine", 999000111, "Um texto muito grande");

	phonebook.addContact(a);
	phonebook.addContact(b);
	phonebook.addContact(c);
	phonebook.addContact(d);
	phonebook.addContact(e);
	phonebook.addContact(f);
	phonebook.addContact(g);
} */

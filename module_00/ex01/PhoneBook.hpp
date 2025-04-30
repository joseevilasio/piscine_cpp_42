#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX 8

class	PhoneBook
{
	private:
		Contact	_contacts[MAX];
		int		_count;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(const Contact& c);
		int		getCount(void) const;
		void	displayAll(void);
		void	displayContact(int id);
};

#endif //PHONEBOOK_HPP
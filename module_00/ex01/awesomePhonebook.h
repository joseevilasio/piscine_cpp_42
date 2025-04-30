#ifndef AWESOME_PHONEBOOK_H
#define AWESOME_PHONEBOOK_H

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <sstream>

void		handleContact(PhoneBook& phonebook);
void		handleSearch(PhoneBook& phonebook);
std::string	trim(const std::string& str);
void		prompt(void);
//void		fillList(PhoneBook& phonebook); //debug

#endif //AWESOME_PHONEBOOK_H
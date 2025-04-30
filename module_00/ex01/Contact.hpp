#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		int			_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		void		setContact(const std::string& firstName,
						const std::string& lastName,
						const std::string& nickname,
						int phoneNumber, const std::string& darkestSecret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		int			getPhoneNumber (void) const;
		std::string	getDarkestSecret(void) const;
};

#endif //CONTACT_HPP
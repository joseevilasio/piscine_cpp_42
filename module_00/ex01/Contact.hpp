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
		Contact();
		~Contact();
		void		setContact(const std::string& firstName,
						const std::string& lastName, const std::string& nickname,
						int phoneNumber, const std::string& darkestSecret);
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber () const;
		std::string	getDarkestSecret() const;
};

#endif //CONTACT_HPP
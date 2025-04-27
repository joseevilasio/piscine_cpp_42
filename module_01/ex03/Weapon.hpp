#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string const type);
		~Weapon(void);
		void				setType(std::string const type);
		const std::string&	getType(void) const;
};

#endif //WEAPON_HPP
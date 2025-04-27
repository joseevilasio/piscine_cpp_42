#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(std::string const name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon& weapon);
};

#endif //HUMAN_B_HPP
#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string const name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};

#endif //HUMAN_A_HPP
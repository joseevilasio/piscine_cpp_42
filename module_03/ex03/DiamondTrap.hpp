#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(const std::string& name);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		DiamondTrap(const DiamondTrap& rhs);
		~DiamondTrap(void);

		void	whoAmI(void);
		//void	display(void); //debug
};


#endif //DIAMONDTRAP_HPP
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		ScavTrap& operator=(const ScavTrap& rhs);
		ScavTrap(const ScavTrap& rhs);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate();

		//void	display(void); //debug
};

#endif //SCAVTRAP_HPP
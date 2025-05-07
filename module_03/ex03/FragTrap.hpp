#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string& name);
		FragTrap& operator=(const FragTrap& rhs);
		FragTrap(const FragTrap& rhs);
		~FragTrap(void);

		void	highFivesGuys(void);

		//void	display(void); //debug
};

#endif //FRAGTRAP_HPP
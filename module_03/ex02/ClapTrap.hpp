#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoint;
		unsigned int	_attackDemage;

	public:
		ClapTrap(const std::string& name);
		ClapTrap& operator=(const ClapTrap& rhs);
		ClapTrap(const ClapTrap& rhs);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDemage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		//void	display(void); //debug
};

#endif //CLAPTRAP_HPP
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria**	_unequipped;
		int			_unequippedCount;
		int			_unequippedCapacity;

	public:

		Character(std::string name);
		Character& operator=(const Character& rhs);
		Character(const Character& rhs);
		~Character(void);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				storeUnequipped(AMateria* m);
};

#endif //CHARACTER_HPP
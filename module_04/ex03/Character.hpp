#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria* _slots[4];

	public:
		Character(void);
		Character& operator=(const Character& rhs);
		Character(const Character& rhs);
		~Character(void);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif //CHARACTER_HPP
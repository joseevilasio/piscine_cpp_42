#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria
{
	protected:

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& rhs);
		AMateria& operator=(const AMateria& rhs);
		~AMateria(void);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif //A_MATERIA_HPP
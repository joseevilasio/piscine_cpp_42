#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		//using AMateria::use;
		Ice(/* std::string const & type */void);
		Ice& operator=(const Ice& rhs);
		Ice(const Ice& rhs);
		virtual ~Ice(void);

		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif //ICE_HPP
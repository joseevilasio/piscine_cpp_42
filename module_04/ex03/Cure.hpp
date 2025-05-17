#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
	public:
		//using AMateria::use;
		Cure(/* std::string const & type */void);
		Cure& operator=(const Cure& rhs);
		Cure(const Cure& rhs);
		virtual ~Cure(void);

		std::string const & getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif //CURE_HPP
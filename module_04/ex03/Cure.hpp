#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure& operator=(const Cure& rhs);
		Cure(const Cure& rhs);
		~Cure(void);

		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif //CURE_HPP
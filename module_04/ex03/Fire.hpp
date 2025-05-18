#ifndef FIRE
#define FIRE

#include "AMateria.hpp"

class Fire : public AMateria
{
	public:
		Fire(void);
		Fire& operator=(const Fire& rhs);
		Fire(const Fire& rhs);
		~Fire(void);

		Fire*	clone() const;
		void	use(ICharacter& target);
};

#endif //FIRE
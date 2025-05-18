#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat(void);
		Cat& operator=(const Cat& rhs);
		Cat(const Cat& rhs);
		~Cat(void);

		void	makeSound(void) const;
};

#endif //CAT_HPP
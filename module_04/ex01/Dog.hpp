#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog(void);
		Dog& operator=(const Dog& rhs);
		Dog(const Dog& rhs);
		~Dog(void);

		void	makeSound(void) const;
};

#endif //DOG_HPP
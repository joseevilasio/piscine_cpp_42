#ifndef DOG_HPP
#define DOG_HPP

#include <string>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog& operator=(const Dog& rhs);
		Dog(const Dog& rhs);
		~Dog(void);

		void	makeSound(void) const;
};

#endif //DOG_HPP
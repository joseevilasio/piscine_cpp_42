#ifndef DOG_HPP
#define DOG_HPP

#include <string>

class Dog : public Animal
{
	protected:
		std::string	_type;

	public:
		Dog(void);
		Dog& operator=(const Dog& rhs);
		Dog(const Dog& rhs);
		~Dog(void);

		const std::string&	getType(void) const;
		void	makeSound(void) const;
};

#endif //DOG_HPP
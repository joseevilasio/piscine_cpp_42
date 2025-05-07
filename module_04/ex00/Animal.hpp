#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal& operator=(const Animal& rhs);
		Animal(const Animal& rhs);
		virtual ~Animal(void);

		virtual const std::string&	getType(void) const;
		virtual void	makeSound(void) const;
};

#endif //ANIMAL_HPP
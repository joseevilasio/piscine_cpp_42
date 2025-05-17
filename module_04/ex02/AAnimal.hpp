#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal(void);
		AAnimal& operator=(const AAnimal& rhs);
		AAnimal(const AAnimal& rhs);
		virtual ~AAnimal(void);

		virtual const std::string&	getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif //A_ANIMAL_HPP
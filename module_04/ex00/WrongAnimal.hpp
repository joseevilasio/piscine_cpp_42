#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		WrongAnimal(const WrongAnimal& rhs);
		~WrongAnimal(void);

		const std::string&	getType(void) const;
		void	makeSound(void) const;
};

#endif //WRONG_ANIMAL_HPP
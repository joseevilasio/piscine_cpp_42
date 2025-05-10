#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat& operator=(const WrongCat& rhs);
		WrongCat(const WrongCat& rhs);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif //WRONG_CAT_HPP
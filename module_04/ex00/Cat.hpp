#ifndef CAT_HPP
#define CAT_HPP

#include <string>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat& operator=(const Cat& rhs);
		Cat(const Cat& rhs);
		~Cat(void);

		void	makeSound(void) const;
};

#endif //CAT_HPP
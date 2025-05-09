#ifndef CAT_HPP
#define CAT_HPP

#include <string>

class Cat : public Animal
{
	
	protected:
		std::string	_type;

	public:
		Cat(void);
		Cat& operator=(const Cat& rhs);
		Cat(const Cat& rhs);
		~Cat(void);

		const std::string&	getType(void) const;
		void	makeSound(void) const;
};

#endif //CAT_HPP
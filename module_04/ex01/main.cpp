#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n -- Basic -- \n\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	std::cout << "\n -- Dog - Deep Copy -- \n\n";

	Dog basic;
	{
		std::cout << std::endl;
		Dog tmp;
		tmp = basic;
		std::cout << std::endl;
	}
	basic.makeSound();

	std::cout << "\n -- Cat - Deep Copy -- \n\n";

	Cat other;
	{
		std::cout << std::endl;
		Cat tmp;
		tmp = other;
		std::cout << std::endl;
	}
	other.makeSound();

	return (0);
}
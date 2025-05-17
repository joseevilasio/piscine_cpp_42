#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	// std::cout << std::endl;

	// AAnimal meta;

	std::cout << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	std::cout << std::endl;

	Dog basic;
	{
		std::cout << std::endl;
		Dog tmp;
		tmp = basic;
		std::cout << std::endl;
	}
	basic.makeSound();

	std::cout << std::endl;

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
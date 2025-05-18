#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include <iostream>

/* int main(void)
{
	// {
	// 	std::cout << " -- AMateria -- " << std::endl;
	// 	Ice ice;
	// 	std::cout << "Type: " << ice.getType() << std::endl;
	// 	Ice* new_ice = ice.clone();
	// 	delete new_ice;

	// 	Cure cure;
	// 	std::cout << "Type: " << cure.getType() << std::endl;
	// 	Cure* new_cure = cure.clone();
	// 	delete new_cure;
	// }

	// {
	// 	std::cout << " -- Character -- " << std::endl;

	// 	AMateria* a;
	// 	AMateria* b;
	// 	AMateria* c;
	// 	AMateria* d;
	// 	AMateria* e = new Ice();

	// 	a = e->clone();
	// 	b = a->clone();
	// 	c = b->clone();
	// 	d = c->clone();

	// 	ICharacter* me = new Character("me");
	// 	me->use(5, *me); //Invalid index
	// 	me->equip(a);
	// 	me->equip(b);
	// 	me->use(1, *me);
	// 	me->use(2, *me); //Empty slot
	// 	me->equip(c);
	// 	me->equip(d);
	// 	me->equip(e); //Full slot

	// 	me->unequip(5); //Invalid index
	// 	me->unequip(3);
	// 	me->unequip(2);
	// 	me->unequip(1);
	// 	me->unequip(0);

	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		me->equip(new Ice());
	// 		me->unequip(0);
	// 	}
		
	// 	std::cout << "Type: " << c->getType() << std::endl; //still


	// 	delete e; //not equip
	// 	delete me;
	// }

	// {
	// 	std::cout << " -- Character -- Deep Copy -- " << std::endl;
	// 	Character a("Jim");
	// 	a.equip(new Cure());
	// 	a.equip(new Ice());

	// 	Character b = a; //Copy
	// 	Character c("Marvin");
	// 	std::cout << "c: " << c.getName() << std::endl;
	// 	c = a; //Copy assignment
	// 	std::cout << "a: " << a.getName() << std::endl;
	// 	std::cout << "b: " << b.getName() << std::endl;
	// 	std::cout << "c: " << c.getName() << std::endl; // Before is was Marvin

	// 	a.use(0, b);
	// }

	// {
	// 	std::cout << " -- MateriaSource -- " << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	std::cout << "Type tmp: " << tmp->getType() << std::endl;

	// 	delete src;
	// 	delete tmp;
	// }

	// {
	// 	std::cout << " -- Other Materia -- " << std::endl;

	// 	ICharacter* me = new Character("me");
	// 	me->equip(new Fire());
	// 	me->use(0, *me);

	// 	delete me;
	// }

	return (0);
} */

/* int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
} */
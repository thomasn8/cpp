#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	AMateria *ice = new Ice;
	AMateria *cure = new Cure;
	AMateria *cure2 = new Cure;
	AMateria *cure3 = new Cure;
	AMateria *ice2 = new Ice;

	ICharacter *character1 = new Character("Thomas");
	character1->equip(ice);
	character1->equip(cure);
	character1->equip(cure2);
	character1->equip(cure3);
	character1->equip(ice2);
	std::cout << *character1 << " - item1: " << character1->getMateria(0)->getType() << std::endl;
	std::cout << *character1 << " - item2: " << character1->getMateria(1)->getType() << std::endl;
	std::cout << *character1 << " - item3: " << character1->getMateria(2)->getType() << std::endl;
	std::cout << *character1 << " - item4: " << character1->getMateria(3)->getType() << std::endl;
	character1->unequip(1);
	character1->equip(ice2);

	ICharacter *character2 = new Character(*character1);
	character2->setName("Charlie");
	std::cout << *character2 << " - item1: " << character2->getMateria(0)->getType() << std::endl;
	std::cout << *character2 << " - item2: " << character2->getMateria(1)->getType() << std::endl;
	std::cout << *character2 << " - item3: " << character2->getMateria(2)->getType() << std::endl;
	std::cout << *character2 << " - item4: " << character2->getMateria(3)->getType() << std::endl;
	character2->use(0, *character1);
	character2->use(2, *character1);

	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;

	return 0;
}

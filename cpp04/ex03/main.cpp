#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	Ice *ice = new Ice;
	Cure *cure = new Cure;
	Cure *cure2 = new Cure;
	Cure *cure3 = new Cure;
	Cure *cure4 = new Cure;
	Character *character1 = new Character;

	character1->equip(ice);
	character1->equip(cure);
	character1->equip(cure2);
	character1->equip(cure3);
	character1->equip(cure4);
	std::cout << "Char1, item1: " << character1->getMateriaPtr(0)->getType() << std::endl;
	std::cout << "Char1, item2: " << character1->getMateriaPtr(1)->getType() << std::endl;
	std::cout << "Char1, item3: " << character1->getMateriaPtr(2)->getType() << std::endl;
	std::cout << "Char1, item4: " << character1->getMateriaPtr(3)->getType() << std::endl;

	Character *character2 = new Character(*character1);
	std::cout << "Char2, item1: " << character2->getMateriaPtr(0)->getType() << std::endl;
	std::cout << "Char2, item2: " << character2->getMateriaPtr(1)->getType() << std::endl;
	std::cout << "Char2, item3: " << character2->getMateriaPtr(2)->getType() << std::endl;
	std::cout << "Char2, item4: " << character2->getMateriaPtr(3)->getType() << std::endl;

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

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{

	// MES TESTS
	ICharacter *character1 = new Character("Thomas");
	AMateria *ice = new Ice;
	AMateria *cure = new Cure;
	AMateria *cure2 = new Cure;
	AMateria *cure3 = new Cure;
	AMateria *ice2 = new Ice;
	character1->equip(ice);
	character1->equip(cure);
	character1->equip(cure2);
	character1->equip(cure3);
	character1->equip(ice2);
	character1->seeEquipement();
	character1->unequip(1);
	character1->seeEquipement();
	character1->equip(ice2);
	character1->seeEquipement();

	std::cout << std::endl;
	ICharacter *character2 = new Character(*character1);
	character2->setName("Charlie");
	character2->seeEquipement();

	std::cout << std::endl;
	character2->use(0, *character1);
	character2->use(2, *character1);

	std::cout << std::endl;
	ICharacter *character3 = new Character();
	character3->seeEquipement();
	*character3 = *character1;
	character3->setName("Albert");
	character3->seeEquipement();

	std::cout << std::endl;
	ICharacter *character4 = new Character("Roni");
	AMateria *roni_ice1 = new Ice;
	AMateria *roni_ice2 = new Ice;
	AMateria *roni_ice3 = new Ice;
	AMateria *roni_ice4 = new Ice;
	character4->equip(roni_ice1);
	character4->equip(roni_ice2);
	character4->equip(roni_ice3);
	character4->equip(roni_ice4);
	character4->unequip(2);
	character4->unequip(3);
	character4->seeEquipement();
	
	std::cout << std::endl;
	*character4 = *character1;
	character4->setName("Roni");
	character4->seeEquipement();
	character4->seeUnquiped();

	ICharacter *character5 = new Character("Selena");
	AMateria *s_ice1 = new Ice;
	AMateria *s_cure = new Cure;
	AMateria *s_cure2 = new Cure;
	AMateria *s_cure3 = new Cure;
	AMateria *s_ice2 = new Ice;
	std::cout << std::endl;
	character5->equip(s_ice1);
	character5->equip(s_cure);
	character5->equip(s_cure2);
	character5->equip(s_cure3);
	character5->equip(s_ice2);
	std::cout << std::endl;
	character5->seeEquipement();
	character5->seeUnquiped();
	std::cout << std::endl;
	character5->unequip(1);
	character5->seeEquipement();
	character5->seeUnquiped();
	std::cout << std::endl;
	character5->equip(s_ice2);
	character5->seeEquipement();
	character5->seeUnquiped();
	std::cout << std::endl;
	character5->unequip(0);
	character5->unequip(1);
	character5->seeEquipement();
	character5->seeUnquiped();

	std::cout << std::endl;
	ICharacter *character6 = new Character(*character5);
	character6->setName("Jordan");
	character6->seeEquipement();
	character6->seeUnquiped();

	std::cout << std::endl;
	delete character5;
	std::cout << std::endl;
	delete character1;
	std::cout << std::endl;
	delete character4;
	std::cout << std::endl;
	delete character2;
	std::cout << std::endl;
	delete character3;
	std::cout << std::endl;
	delete character6;
	

	// SUBJECT TESTS
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

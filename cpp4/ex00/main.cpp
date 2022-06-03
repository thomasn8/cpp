#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// CORRECT CLASSES
	// grâce a virtual, le compilo comprend quelle fonction utiliser dynamiquement malgré le type du pointeur
	// on parle alors de méthodes
	std::cout << std::endl << "CORRECT CLASSES USING VIRTUAL" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	std::cout << std::endl;
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << std::endl;


	// WRONG CLASSES
	// sans virtual, le compilo comprend qu'il faut utiliser les fonctions du type utilisé (ici WrongAnimal)
	// on parle alors de fonctions membres statiques
	std::cout << std::endl << "WRONG CLASSES NOT USING VIRTUAL" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();

	std::cout << std::endl;
	std::cout << meta2->getType() << ": ";
	meta2->makeSound();
	std::cout << std::endl;
	std::cout << h->getType() << ": ";
	h->makeSound();
	std::cout << " -> WRONG, it is supposed to be a cat..." << std::endl;


	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	delete meta2;
	delete h;

	return 0;
}

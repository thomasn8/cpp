#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	// CORRECT CLASSES
	std::cout << std::endl << "CORRECT CLASSES:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	std::cout << std::endl;
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << j->getType() << ": ";
	j->makeSound();




	// WRONG CLASSES
	std::cout << std::endl;
	std::cout << std::endl << "WRONG CLASSES:" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();

	std::cout << std::endl;
	std::cout << meta2->getType() << ": ";
	meta2->makeSound();
	std::cout << h->getType() << ": ";
	h->makeSound();

	return 0;
}

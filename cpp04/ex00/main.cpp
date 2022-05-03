#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	// WRONG CLASSES
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* h = new WrongCat();
	std::cout << std::endl;
	std::cout << h->getType() << " " << std::endl;
	h->makeSound();
	meta2->makeSound();

	return 0;
}

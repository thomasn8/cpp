#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal *animal = new Animal();	// rend la compilation impossible (c'est le but)
	Animal *cat = new Cat();
	Animal *dog = new Dog();
	std::cout << std::endl;
	delete cat;
	delete dog;


	// MAIN DE L'EXO PRÉCÉDANT
	// int	N = 10;
	// Animal	*animals[N];

	// std::cout << std::endl;
	// for (int i = 0; i < N; i++)
	// {
	// 	if (i < (N / 2))
	// 		animals[i] = new Cat();
	// 	else
	// 		animals[i] = new Dog();
	// 	std::cout << std::endl;
	// }
	// for (int i = 0; i < N; i++)
	// {
	// 	delete animals[i];
	// 	std::cout << std::endl;
	// }

	return 0;
}

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// SUBJECT'S MAIN
	std::cout << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	std::cout << std::endl << std::endl;


	// MY MAIN
	int	N = 10;
	Animal	*animals[N];

	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i < (N / 2))
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 0; i < N; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
	return 0;
}

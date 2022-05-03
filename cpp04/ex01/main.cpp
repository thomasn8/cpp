#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
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

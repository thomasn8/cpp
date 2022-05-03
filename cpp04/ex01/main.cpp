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
	
	for (int i = 0; i < 10; i++)
	{
		// if (i < (N / 2))
		// 	delete (Cat *)animals[i];
		// else
		// 	delete (Dog *)animals[i];

		delete animals[i];	
	}

	return 0;
}

/* 
	Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la
	moitié est composée d’objets Dog et l’autre moitié d’objets Cat. 
	
	À la fin de l’exécution
	du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete
	directement les chiens et les chats en tant qu’Animal. Les destructeurs correspondants
	doivent être appelés dans le bon ordre.
*/
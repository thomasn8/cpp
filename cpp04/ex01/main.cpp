#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal *solitaire = new Cat();
	// // delete (Cat *)solitaire;
	// delete solitaire;
	// std::cout << std::endl;


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
	
	animals[0]->makeSound();
	std::cout << std::endl;
	animals[6]->makeSound();
	
	for (int i = 0; i < 10; i++)
	{
		if (i < (N / 2))
			delete (Cat *)animals[i];
		else
			delete (Dog *)animals[i];
	}

	// int	N = 10;
	// Animal	*animals = new Animal[N];
	// std::cout << std::endl;

	// for (int i = 0; i < N; i++)
	// {
	// 	if (i < (N / 2))
	// 		animals[i] = *new Cat();
	// 	else
	// 		animals[i] = *new Dog();
	// 	std::cout << std::endl;
	// }

	// animals[0].makeSound();
	// std::cout << std::endl;
	// animals[6].makeSound();
	// std::cout << std::endl;

	// std::cout << "NEW: " << new Dog() << std::endl;	// new Dog() renvoie un pointeur

	// int	N = 10;
	// void	*animals[N];		// tableau de 10 ptr
	// // std::cout << animals[0] << "/" << animals[1] << std::endl;
	// for (int i = 0; i < N; i++)
	// {
	// 	if (i < (N / 2))
	// 		animals[i] = new Cat();
	// 	else
	// 		animals[i] = new Dog();
	// 	std::cout << std::endl;
	// }
	// // std::cout << animals[0] << "/" << animals[6] << std::endl;
	// std::cout << *(Animal *)animals[0] << "/" << *(Animal *)animals[6] << std::endl;

	// *(Animal *)animals[1].makeSound();
	
	// for (int i = N - 1; i >= 0; i--)
	// {
	// 	// if (i < (N / 2))
	// 	// 	delete &animals[i];
	// 	// else
	// 	// 	delete &animals[i];

	// 	// if (i < (N / 2))
	// 	// 	delete (Cat *)&animals[i];
	// 	// else
	// 	// 	delete (Dog *)&animals[i];
		
	// 	delete &animals[i];
	// 	std::cout << std::endl;
	// }
	// delete [] animals;

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
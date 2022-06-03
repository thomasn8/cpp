#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie		*first;
	int			n;
	std::string name;

	if (ac != 3)
	{
		std::cout << "Usage: ./zombieHorde number_of_zombies name_of_zombie_species" << std::endl;
		return 1;
	}
	n = atoi(av[1]);
	if (n <= 0 || n > 250)
	{
		std::cout << "number_of_zombies must between 1 and 250" << std::endl;
		return 1;
	}
	name = av[2];
	for (int j = 0 ; j < name.length() ; j++)
	{
		if (name.c_str()[j] < ' ' || name.c_str()[j] > '~')
		{
			std::cout << "name_of_zombie_species musts contain only printable characters" << std::endl;
			return 1;
		}
	}
	first = zombieHorde(n, name);
	delete [] first; 
	return 0;
}

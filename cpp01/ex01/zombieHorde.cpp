#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*first = new Zombie[N];
	Zombie	*zombie_ptr = first;

	i = -1;
	while (++i < N)
	{
		zombie_ptr->name = name;
		zombie_ptr->announce();
		zombie_ptr++;
	}
	return (first);
}

#include "Zombie.hpp"

/* 
	It must allocate N Zombie objects in a single allocation. 
	Then, it has to initialize the zombies, giving each one of them the name passed as parameter. 
	The function returns a pointer to the first zombie.
	Implement your own tests to ensure your zombieHorde() function works as expected.
	Try to call announce() for each one of the zombies.
	Don’t forget to delete all the zombies and check for memory leaks.
*/

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

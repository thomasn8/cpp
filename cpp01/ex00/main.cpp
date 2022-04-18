#include "Zombie.hpp"

/*
	What is the actual point of the exercise?
	You have to determine in what case it’s better to allocate the zombies on the stack or heap.

	Zombies must be destroyed when you don’t need them anymore. 
	The destructor must print a message with the name of the zombie for debugging purposes.
*/

int	main(void)
{
	// example of stack allocation :
	// here the zombie is constructed and destructed in the randomChump() function
	// PS: "random chump" means "bon à rien" ...
	randomChump("Isa");

	// example of heap allocation :
	// here the zombie is now accessible in the main
	Zombie	*p;
	p = newZombie("Karl");
	delete p;

	return 0;
}

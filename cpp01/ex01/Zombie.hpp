#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		std::string	name;
};

Zombie*		zombieHorde(int N, std::string name);

#endif

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...	(" << this << ")" << std::endl;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead.			(" << this << ")" << std::endl;
}

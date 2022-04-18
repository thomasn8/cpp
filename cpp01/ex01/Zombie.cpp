#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "Zombie " << this->name <<\
		" is born: Mon sang pour la horde! ("\
		<< this << ")" << std::endl;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name <<\
		" is dead. ††††††††††††††††††††††† ("\
		<< this << ")" << std::endl;
}

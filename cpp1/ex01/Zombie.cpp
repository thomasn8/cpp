#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << "A zombie " << this->name <<\
		" is born: Mon sang pour la horde! ("\
		<< this << ")" << std::endl;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "A zombie " << this->name <<\
		" is dead. † † † † † † † † † † † † ("\
		<< this << ")" << std::endl;
}

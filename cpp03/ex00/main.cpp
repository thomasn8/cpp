#include "ClapTrap.hpp"

int	main()
{
	ClapTrap jana("jana");
	ClapTrap malika("malika");

	jana.attack("malika");
	malika.takeDamage(jana.getAttackDamage());

	std::cout << std::endl;
	std::cout << jana << std::endl;
	std::cout << malika << std::endl;
	std::cout << std::endl;

	return 0;
}

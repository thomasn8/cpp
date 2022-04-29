#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	/*
		EX00
	*/
	// ClapTrap jana("jana");
	// ClapTrap malika("malika");

	// jana.attack("malika");
	// malika.takeDamage(jana.getAttackDamage());

	// std::cout << std::endl;
	// std::cout << jana << std::endl;
	// std::cout << malika << std::endl;
	// std::cout << std::endl;


	/*
		EX01
	*/
	ScavTrap douglas("douglas");	// c.name + s.name
	ScavTrap douglas2;				// c.default + s.default
	douglas2 = douglas;				// s.copy assign.
	ScavTrap paulo("paulo");		// c.name + s.name
	ScavTrap paulo2(paulo);			// c.default + s.copy

	std::cout << std::endl;
	std::cout << "doulas2: " << douglas2 << std::endl;
	std::cout << "paulo2: " << paulo2 << std::endl;
	std::cout << std::endl;

	douglas.attack("paulo");
	paulo.takeDamage(douglas.getAttackDamage());

	std::cout << std::endl;
	std::cout << douglas << std::endl;
	std::cout << paulo << std::endl;
	std::cout << std::endl;

	return 0;
}

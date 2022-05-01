#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap edgar("edgar");

	std::cout << std::endl;
	std::cout << edgar << std::endl;
	edgar.attack("a ghost");
	edgar.whoAmI();
	edgar.guardGate();
	edgar.highFivesGuys();
	std::cout << std::endl;

	DiamondTrap luis;
	luis = edgar;
	luis.setName("luis");
	std::cout << std::endl;
	std::cout << luis << std::endl;
	luis.whoAmI();
	std::cout << std::endl;

	return 0;
}

#ifndef SVACTRAP_HPP
# define SVACTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{

	public:

		ScavTrap & operator=(ScavTrap const & rhs);
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();

		void 	attack(const std::string & target);
		void	guardGate(void) const;
	
	protected :

		int		_energyPoints;
};

std::ostream	& operator<<(std::ostream & o, ScavTrap const & inst);

#endif

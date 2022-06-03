#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap & operator=(FragTrap const & rhs);
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();

		void 	attack(const std::string & target);
		void	highFivesGuys(void) const;
	
	protected:
	
		int		_attackDamage;
};

std::ostream	& operator<<(std::ostream & o, FragTrap const & inst);

#endif

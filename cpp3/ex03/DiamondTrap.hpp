#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap & operator=(DiamondTrap const & rhs);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap(std::string name);
		DiamondTrap();
		~DiamondTrap();

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void		setName(std::string name);

		void 		attack(const std::string & target);
		void		whoAmI(void);

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, DiamondTrap const & inst);

#endif

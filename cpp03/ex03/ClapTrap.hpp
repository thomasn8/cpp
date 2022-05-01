#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{

	public:

		ClapTrap & operator=(ClapTrap const & rhs);
		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string name);
		ClapTrap();
		~ClapTrap();

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void 		attack(const std::string & target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	protected:
	
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
};

std::ostream	& operator<<(std::ostream & o, ClapTrap const & inst);

#endif

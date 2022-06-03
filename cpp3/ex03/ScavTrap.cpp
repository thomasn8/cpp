#include "ScavTrap.hpp"

/* *****************
	Main actions
***************** */

void		ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap entered the gatekeeper mode";
	std::cout << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
		return ;

	this->_energyPoints--;

	std::cout << "SCAV-attack from " << this->_name << " to " << target;
	std::cout << " causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, ScavTrap const & inst)
{
	o << inst.getName() << " (";
	o << inst.getHitPoints() << "HP/";
	o << inst.getEnergyPoints() << "E)";
	return o;
}

ScavTrap	& ScavTrap::operator=(ScavTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "(assign.) A scavtrap clowned another scavtrap" << std::endl;
	return *this;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap()
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "(copy) A claptrap evolved to scavtrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "(name) A claptrap evolved to scavtrap" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "(default) A claptrap evolved to scavtrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "...and its scav-evolution" << std::endl;
}

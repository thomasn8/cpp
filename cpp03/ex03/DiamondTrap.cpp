#include "DiamondTrap.hpp"

/* *****************
	Main actions
***************** */

void	DiamondTrap::attack(const std::string & target)
{
	this->ScavTrap::attack(target);
}



void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
	this->FragTrap::_name = std::string(name).append("_clap_name");
	this->ScavTrap::_name = std::string(name).append("_clap_name");
}


/* *****************
	Getters
***************** */

std::string	DiamondTrap::getName(void) const
{
	return this->_name;
}

int			DiamondTrap::getHitPoints(void) const
{
	return this->_hitPoints;

}

int			DiamondTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			DiamondTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, DiamondTrap const & inst)
{
	o << inst.getName() << " (";
	o << inst.getHitPoints() << "HP/";
	o << inst.getEnergyPoints() << "E/";
	o << inst.getAttackDamage() << "Atk)";
	return o;
}

DiamondTrap	& DiamondTrap::operator=(DiamondTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "(assign.) A diamondtrap clowned another diamondtrap" << std::endl;
	return *this;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : 
ScavTrap(), 
FragTrap()
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "(copy) A scavfrag-hybrid evolved to diamondtrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
ScavTrap(std::string(name).append("_clap_name")), 
FragTrap(std::string(name).append("_clap_name")), 
_name(name)
{
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "(name) A scavfrag-hybrid evolved to diamondtrap" << std::endl;
}

DiamondTrap::DiamondTrap() :
ScavTrap(), 
FragTrap()
{
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "(default) A scavfrag-hybrid evolved to diamondtrap" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "(default) A diamondtrap lost its evolution" << std::endl;
}

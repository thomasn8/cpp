#include "FragTrap.hpp"

/* *****************
	Main actions
***************** */

void		FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap: \"HIGH-FIVES ?!?\"";
	std::cout << std::endl;
}

void FragTrap::attack(const std::string & target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
		return ;

	this->_energyPoints--;

	std::cout << "FRAG-attack from " << this->_name << " to " << target;
	std::cout << " causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, FragTrap const & inst)
{
	o << inst.getName() << " (";
	o << inst.getHitPoints() << "HP/";
	o << inst.getEnergyPoints() << "E)";
	return o;
}

FragTrap	& FragTrap::operator=(FragTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "(assign.) ...and fragtrap" << std::endl;
	return *this;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "(copy) ...and to fragtrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "(name) ...and to fragtrap" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "(default) ...and to fragtrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "...its frag-evolution " << std::endl;
}

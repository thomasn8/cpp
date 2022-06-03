#include "FragTrap.hpp"

/* *****************
	Main actions
***************** */

void		FragTrap::highFivesGuys(void) const
{
	std::cout << this->_name << ": \"HIGH-FIVES ?!?\"";
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
	std::cout << " causing " << this->getAttackDamage() << " points of damage!";
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
	std::cout << "(assign.) A fragtrap clowned another fragtrap" << std::endl;
	return *this;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "(copy) A claptrap evolved to fragtrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "(name) A claptrap evolved to fragtrap" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "(default) A claptrap evolved to fragtrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "(default) A fragtrap lost its evolution" << std::endl;
}

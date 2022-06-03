#include "ClapTrap.hpp"

/* *****************
	Main actions
***************** */

void ClapTrap::attack(const std::string & target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
		return ;

	this->_energyPoints--;

	std::cout << this->_name << " attacks " << target;
	std::cout << " causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	
	std::cout << this->_name << " gets " << amount << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int	prevHitPoints;
	int	gain;

	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
		return ;

	prevHitPoints = this->_hitPoints;
	this->_energyPoints--;
	this->_hitPoints += amount;
	if (this->_hitPoints > 10)
	{
		gain = 10 - prevHitPoints;
		this->_hitPoints = 10;
	}

	std::cout << this->_name << " recovers " << gain << " HP";
	std::cout << " and has now " << this->_hitPoints << " HP";
	std::cout << std::endl;
}


/* *****************
	Getters
***************** */

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

int			ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;

}

int			ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, ClapTrap const & inst)
{
	o << inst.getName() << " (";
	o << inst.getHitPoints() << "HP/";
	o << inst.getEnergyPoints() << "E)";
	return o;
}

ClapTrap	& ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "(assign.) A claptrap is born" << std::endl;
	return *this;
}

ClapTrap::ClapTrap(ClapTrap const & src) :
_name(src.getName()), _hitPoints(src.getHitPoints()),
_energyPoints(src.getEnergyPoints()), _attackDamage(src.getAttackDamage())
{
	std::cout << "(copy) A claptrap is born" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "(name) A claptrap is born" << std::endl;
}

ClapTrap::ClapTrap() : 
_name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "(default) A claptrap is born" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A claptrap is dead" << std::endl;
}

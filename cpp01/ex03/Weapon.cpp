#include "Weapon.hpp"

std::string	&Weapon::getType(void) const
{
	return (this->_typeRef);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string type) : _type(type), _typeRef(this->_type)
{
	return;
}

Weapon::~Weapon(void)
{
	return;
}

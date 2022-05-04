#include "Cure.hpp"

/* *****************
	Main actions
***************** */

Cure *Cure::clone() const
{
	Cure *cure = new Cure(*this);
	return cure;
}

void Cure::use(Character & target)
{
	std::cout << "* heals " << target << "’s wounds *" << std::endl;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Cure const & instance)
{
	o << instance.getType();
	return o;
}

Cure	& Cure::operator=(Cure const & src)
{
	this->_type = src.getType();
	std::cout << "(assign.) Cure has been copied" << std::endl;
	return *this;
}

Cure::Cure(Cure const & src)
{
	this->_type = src.getType();
	std::cout << "(copy) Cure has been created" << std::endl;
}

Cure::Cure()
{
	this->_type = "cure";
	std::cout << "(default) Cure has been created" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure has been destroyed" << std::endl;
}

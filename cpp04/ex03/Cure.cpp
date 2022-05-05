#include "Cure.hpp"

/* *****************
	Main actions
***************** */

AMateria *Cure::clone() const
{
	Cure *cure = new Cure(*this);
	std::cout << "Cure has been clowned" << std::endl;
	return cure;
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target << "’s wounds *" << std::endl;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Cure const & instance)
{
	o << instance.getType() << "(" << &instance << ")";
	return o;
}

Cure	& Cure::operator=(Cure const & src)
{
	this->_type = src.getType();
	std::cout << "(assign.) Cure has been copied - " << this << std::endl;
	return *this;
}

Cure::Cure(Cure const & src)
{
	this->_type = src.getType();
	std::cout << "(copy) Cure has been created - " << this << std::endl;
}

Cure::Cure()
{
	this->_type = "cure";
	std::cout << "(default) Cure has been created - " << this << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure has been destroyed - " << this << std::endl;
}

#include "Cure.hpp"

/* *****************
	Main actions
***************** */

Cure *Cure::clone() const
{
	Cure *Cure = new Cure(*this);
	return Cure;
}

void Cure::use(Character & target)
{
	std::cout << "* heals " << target << "’s wounds *" << std::endl;
}


/* *****************
	Getters
***************** */

std::string const & Cure::getType() const
{
	return this->_type;
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

Cure::Cure(Cure const & src) :
_type(src.getType()),
{
	std::cout << "(copy) Cure has been created" << std::endl;
}

Cure::Cure() :
_type("cure"),
{
	std::cout << "(default) Cure has been created" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure has been destroyed" << std::endl;
}

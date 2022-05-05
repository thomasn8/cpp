#include "Ice.hpp"

/* *****************
	Main actions
***************** */

AMateria *Ice::clone() const
{
	Ice *ice = new Ice(*this);
	std::cout << "Ice has been clowned" << std::endl;
	return ice;
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Ice const & instance)
{
	o << instance.getType() << "(" << &instance << ")";
	return o;
}

Ice	& Ice::operator=(Ice const & src)
{
	this->_type = src.getType();
	std::cout << "(assign.) Ice has been copied - " << this << std::endl;
	return *this;
}

Ice::Ice(Ice const & src)
{
	this->_type = src.getType();
	std::cout << "(copy) Ice has been created - " << this << std::endl;
}

Ice::Ice()
{
	this->_type = "ice";
	std::cout << "(default) Ice has been created - " << this << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice has been destroyed - " << this << std::endl;
}

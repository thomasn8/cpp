#include "AMateria.hpp"

/* *****************
	Main actions
***************** */

void AMateria::use(ICharacter & target)
{
	return;
}


/* *****************
	Getters
***************** */

std::string const & AMateria::getType() const
{
	return this->_type;
}


/* *****************
	Canonical
***************** */

AMateria	& AMateria::operator=(AMateria const & src)
{
	this->_type = src.getType();
	std::cout << "(assign.) AMateria has been created - " << this << std::endl;
	return *this;
}

AMateria::AMateria(AMateria const & src) :
_type(src.getType())
{
	std::cout << "(copy) AMateria has been created - " << this << std::endl;
}

AMateria::AMateria(std::string const & type) :
_type(type)
{
	std::cout << "(string) AMateria has been created - " << this << std::endl;
}

AMateria::AMateria() :
_type("unknown")
{
	std::cout << "(default) AMateria has been created - " << this << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria has been destroyed - " << this << std::endl;
}

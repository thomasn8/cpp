#include "Unequiped.hpp"

/* *****************
	Canonical
***************** */

Unequiped	& Unequiped::operator=(Unequiped const & src)
{
	(void) src;
	this->materia = NULL;
	this->next = NULL;
	std::cout << "(assign.) Unequiped has been copied - " << this << std::endl;
	return *this;
}

Unequiped::Unequiped(Unequiped const & src) :
materia(NULL),
next(NULL)
{
	(void) src;
	std::cout << "(copy) Unequiped has been created - " << this << std::endl;
}

Unequiped::Unequiped() :
materia(NULL),
next(NULL)
{
	std::cout << "(default) Unequiped has been created - " << this << std::endl;
}

Unequiped::~Unequiped()
{
	std::cout << "Unequiped has been destroyed - " << this << std::endl;
}

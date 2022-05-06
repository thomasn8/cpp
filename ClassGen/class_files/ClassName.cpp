#include "ClassName.hpp"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void ClassName::setName(std::string const & name)
{
	this->_name = name;
}

std::string	ClassName::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, ClassName const & instance)
{
	o << instance.getName();
	return o;
}

ClassName	& ClassName::operator=(ClassName const & src)
{
	this->_name = src.getName();
	std::cout << "(" << this << " - assign.) ClassName (" << &src << ") copied" << std::endl;
	return *this;
}

ClassName::ClassName(ClassName const & src) :
_name(src.getName())
{
	std::cout << "(" << this << " - copy) ClassName created" << std::endl;
}

ClassName::ClassName(std::string const & name) :
_name(name)
{
	std::cout << "(" << this << " - string) ClassName created" << std::endl;
}

ClassName::ClassName()
{
	std::cout << "(" << this << " - default) ClassName created" << std::endl;
}

ClassName::~ClassName()
{
	std::cout << "(" << this << " - default) ClassName destroyed" << std::endl;
}

#include "Bureaucrat.hpp"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void Bureaucrat::setName(std::string const & name)
{
	this->_name = name;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Bureaucrat const & instance)
{
	o << instance.getName();
	return o;
}

Bureaucrat	& Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_name = src.getName();
	std::cout << "(" << this << " - assign.) Bureaucrat (" << &src << ") copied" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
_name(src.getName())
{
	std::cout << "(" << this << " - copy) Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name) :
_name(name)
{
	std::cout << "(" << this << " - string) Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat()
{
	std::cout << "(" << this << " - default) Bureaucrat created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "(" << this << " - default) Bureaucrat destroyed" << std::endl;
}

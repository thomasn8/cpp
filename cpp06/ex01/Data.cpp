#include "Data.hpp"

/* *****************
	Getters/Setters
***************** */

void Data::setName(std::string const & name)
{
	this->_name = name;
}

std::string	Data::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Data const & instance)
{
	o << instance.getName();
	return o;
}

Data	& Data::operator=(Data const & src)
{
	this->_name = src.getName();
	std::cout << "(" << this << " - assign.) Data (" << &src << ") copied" << std::endl;
	return *this;
}

Data::Data(Data const & src) :
_name(src.getName())
{
	std::cout << "(" << this << " - copy) Data created" << std::endl;
}

Data::Data(std::string const & name, int id) :
_name(name),
_id(id)
{
	std::cout << "(" << this << " - string) Data created" << std::endl;
}

Data::Data()
{
	std::cout << "(" << this << " - default) Data created" << std::endl;
}

Data::~Data()
{
	std::cout << "(" << this << " - default) Data destroyed" << std::endl;
}

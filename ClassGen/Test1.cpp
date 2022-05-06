#include "Test1.hpp"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void Test1::setName(std::string const & name)
{
	this->_name = name;
}

std::string	Test1::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Test1 const & instance)
{
	o << instance.getName();
	return o;
}

Test1	& Test1::operator=(Test1 const & src)
{
	this->_name = src.getName();
	std::cout << "(" << this << " - assign.) Test1 (" << &src << ") copied" << std::endl;
	return *this;
}

Test1::Test1(Test1 const & src) :
_name(src.getName())
{
	std::cout << "(" << this << " - copy) Test1 created" << std::endl;
}

Test1::Test1(std::string const & name) :
_name(name)
{
	std::cout << "(" << this << " - string) Test1 created" << std::endl;
}

Test1::Test1()
{
	std::cout << "(" << this << " - default) Test1 created" << std::endl;
}

Test1::~Test1()
{
	std::cout << "(" << this << " - default) Test1 destroyed" << std::endl;
}

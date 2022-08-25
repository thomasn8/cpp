#include "Test.hpp"

/* *****************
	...
***************** */




/* *****************
	Getters/Setters
***************** */

void Test::setId(int id)
{
	this->_id = id;
}

int	Test::getId() const
{
	return this->_id;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Test const & instance)
{
	o << instance.getId();
	return o;
}

Test	& Test::operator=(Test const & src)
{
	this->_id = src.getId();
	return *this;
}

Test::Test(Test const & src) :
_id(src.getId())
{
}

Test::Test(int id) :
_id(id),
_money(100),
_letter('a'),
_letter2('b'),
_letter3('c'),
_letter4('d'),
_letter5('d')
{
}

Test::Test()
{
}

Test::~Test()
{
}

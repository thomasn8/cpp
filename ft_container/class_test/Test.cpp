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
	std::cout << "(" << this << " - assign.) Test (" << &src << ") copied" << std::endl;
	return *this;
}

Test::Test(Test const & src) :
_id(src.getId())
{
	std::cout << "(" << this << " - copy) Test created" << std::endl;
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
	std::cout << "I've got " << this->_money << " francs. " << this->_letter << this->_letter2 << this->_letter3 << this->_letter4 << this->_letter5 << std::endl;
	std::cout << "(" << this << " - int) Test created" << std::endl;
}

Test::Test()
{
	std::cout << "(" << this << " - default) Test created" << std::endl;
}

Test::~Test()
{
	std::cout << "(" << this << " - default) Test destroyed" << std::endl;
}

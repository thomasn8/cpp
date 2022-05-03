#include "Dog.hpp"

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Dog const & instance)
{
	o << instance.getType();
	return o;
}

Dog	& Dog::operator=(Dog const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(assign.) A Dog is born" << std::endl;
	return *this;
}

Dog::Dog(Dog const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(copy) A Dog is born" << std::endl;
}

Dog::Dog()
{
	this->_type = "Dog";
	this->_sound = "Wouf!";
	std::cout << "(default) A Dog is born" << std::endl;
}

Dog::~Dog()
{
	std::cout << "A Dog is dead" << std::endl;
}

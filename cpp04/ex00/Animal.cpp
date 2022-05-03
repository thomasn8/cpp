#include "Animal.hpp"

/* *****************
	Main actions
***************** */

void		Animal::makeSound() const
{
	std::cout << this->_sound << std::endl;
}

/* *****************
	Getters
***************** */

std::string	Animal::getSound() const
{
	return this->_sound;
}

std::string	Animal::getType() const
{
	return this->_type;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Animal const & instance)
{
	o << instance.getType();
	return o;
}

Animal	& Animal::operator=(Animal const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(assign.) An Animal is born" << std::endl;
	return *this;
}

Animal::Animal(Animal const & src) :
_type(src.getType()),
_sound(src.getSound())
{
	std::cout << "(copy) An Animal is born" << std::endl;
}

Animal::Animal() :
_type("unknown"),
_sound("Hello World!")
{
	std::cout << "(default) An Animal is born" << std::endl;
}

Animal::~Animal()
{
	std::cout << "An Animal is dead" << std::endl;
}

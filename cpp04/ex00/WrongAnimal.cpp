#include "WrongAnimal.hpp"

/* *****************
	Main actions
***************** */

void		WrongAnimal::makeSound() const
{
	std::cout << this->_sound << std::endl;
}

/* *****************
	Getters
***************** */

std::string	WrongAnimal::getSound() const
{
	return this->_sound;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, WrongAnimal const & instance)
{
	o << instance.getType();
	return o;
}

WrongAnimal	& WrongAnimal::operator=(WrongAnimal const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(assign.) A WrongAnimal is born" << std::endl;
	return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) :
_type(src.getType()),
_sound(src.getSound())
{
	std::cout << "(copy) A WrongAnimal is born" << std::endl;
}

WrongAnimal::WrongAnimal() :
_type("unknown"),
_sound("Hello WrongWorld!")
{
	std::cout << "(default) A WrongAnimal is born" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "A WrongAnimal is dead" << std::endl;
}

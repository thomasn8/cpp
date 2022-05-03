#include "WrongAnimal.hpp"

/* *****************
	Main actions
***************** */

void		WrongAnimal::makeSound() const
{
	std::cout << this->_sound;
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
	std::cout << "(assign.) A weird Animal is born" << std::endl;
	return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) :
_type(src.getType()),
_sound(src.getSound())
{
	std::cout << "(copy) A weird Animal is born" << std::endl;
}

WrongAnimal::WrongAnimal() :
_type("unknown"),
_sound("Hello World!")
{
	std::cout << "(default) A weird Animal is born" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Poor weird Animal... Rest in peace" << std::endl;
}

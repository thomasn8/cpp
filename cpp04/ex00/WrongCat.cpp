#include "WrongCat.hpp"

/* *****************
	Main actions
***************** */

void		WrongCat::makeSound() const
{
	std::cout << this->_sound << std::endl;
}


/* *****************
	Getters
***************** */

std::string	WrongCat::getSound() const
{
	return this->_sound;
}

std::string	WrongCat::getType() const
{
	return this->_type;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, WrongCat const & instance)
{
	o << instance.getType();
	return o;
}

WrongCat	& WrongCat::operator=(WrongCat const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(assign.) A WrongCat is born" << std::endl;
	return *this;
}

WrongCat::WrongCat(WrongCat const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(copy) A WrongCat is born" << std::endl;
}

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	this->_sound = "WrongMiaou!";
	std::cout << "(default) A WrongCat is born" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat is dead" << std::endl;
}

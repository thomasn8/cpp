#include "WrongCat.hpp"

/* *****************
	Main actions
***************** */

void		WrongCat::makeSound() const
{
	std::cout << this->_sound;
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
	std::cout << "(assign.) ...it's a strange Cat" << std::endl;
	return *this;
}

WrongCat::WrongCat(WrongCat const & src) :
WrongAnimal()
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(copy) ...it's a strange Cat" << std::endl;
}

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	this->_sound = "WrongMiaou!";
	std::cout << "(default) ...it's a strange Cat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A weird Cat is dead" << std::endl;
}

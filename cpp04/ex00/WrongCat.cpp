#include "WrongCat.hpp"

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
	this->WrongAnimal::_sound = src.getSound();
	std::cout << "(assign.) A WrongCat is born" << std::endl;
	return *this;
}

WrongCat::WrongCat(WrongCat const & src)
{
	this->WrongAnimal::_type = src.getType();
	this->WrongAnimal::_sound = src.getSound();
	std::cout << "(copy) A WrongCat is born" << std::endl;
}

WrongCat::WrongCat()
{
	this->WrongAnimal::_type = "WrongCat";
	this->WrongAnimal::_sound = "WrongMiaou!";
	std::cout << "(default) A WrongCat is born" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat is dead" << std::endl;
}

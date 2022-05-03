#include "Cat.hpp"

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Cat const & instance)
{
	o << instance.getType();
	return o;
}

Cat	& Cat::operator=(Cat const & src)
{
	this->_type = src.getType();
	this->Animal::_sound = src.getSound();
	std::cout << "(assign.) A Cat is born" << std::endl;
	return *this;
}

Cat::Cat(Cat const & src)
{
	this->Animal::_type = src.getType();
	this->Animal::_sound = src.getSound();
	std::cout << "(copy) A Cat is born" << std::endl;
}

Cat::Cat()
{
	this->Animal::_type = "Cat";
	this->Animal::_sound = "Miaou!";
	std::cout << "(default) A Cat is born" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A Cat is dead" << std::endl;
}

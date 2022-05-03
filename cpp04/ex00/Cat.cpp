#include "Cat.hpp"

/* *****************
	Main actions
***************** */

void		Cat::makeSound() const
{
	std::cout << this->_sound;
}


/* *****************
	Getters
***************** */

std::string	Cat::getSound() const
{
	return this->_sound;
}

std::string	Cat::getType() const
{
	return this->_type;
}


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
	this->_sound = src.getSound();
	std::cout << "(assign.) ...it's a Cat" << std::endl;
	return *this;
}

Cat::Cat(Cat const & src)
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	std::cout << "(copy) ...it's a Cat" << std::endl;
}

Cat::Cat()
{
	this->_type = "Cat";
	this->_sound = "Miaou!";
	std::cout << "(default) ...it's a Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "A Cat is dead" << std::endl;
}

#include "Dog.hpp"

/* *****************
	Main actions
***************** */

void		Dog::makeSound() const
{
	std::cout << this->_sound;
}


/* *****************
	Getters
***************** */

std::string	Dog::getSound() const
{
	return this->_sound;
}

std::string	Dog::getType() const
{
	return this->_type;
}


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
	this->brain = src.brain;
	std::cout << "(assign.) ...it's a Dog" << std::endl;
	return *this;
}

Dog::Dog(Dog const & src) :
Animal()
{
	this->_type = src.getType();
	this->_sound = src.getSound();
	this->brain = src.brain;
	std::cout << "(copy) ...it's a Dog" << std::endl;
}

Dog::Dog()
{
	this->_type = "Dog";
	this->_sound = "Wouf!";
	this->brain = new Brain(this->_type);
	std::cout << "(default) ...it's a Dog" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "A Dog is dead" << std::endl;
}

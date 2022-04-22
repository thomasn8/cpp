#include "Fixed.hpp"

/* **************************************************** */
/* ******************** CONVERSION ******************** */

float	Fixed::convertFracPart(float const f) const
{
	float		r;
	std::string bits;
	float		res;

	r = this->calcFracPart(f);
	bits = this->calcBits(r, this->_prec);
	res = this->calcBitsToFloat(bits, this->_prec);
	return res;
}

// Une fonction membre qui convertit la valeur en virgule fixe en nombre entier.
int 	Fixed::toInt(void) const
{
	return this->getIntPart();
}

// Une fonction membre qui convertit la valeur en virgule fixe en nombre à virgule flottante.
float	Fixed::toFloat(void) const
{
	return this->_float;
}

/* ************************************************ */
/* ******************** SETTER ******************** */

void Fixed::setIntPart(float const f)
{
	this->_intPart = (int)f;
}

void Fixed::setFracPart(float const f)
{
	this->_fracPart = this->convertFracPart(f);
}

void Fixed::setRawBits(int const raw)
{
}

/* ************************************************ */
/* ******************** GETTER ******************** */

int		Fixed::getIntPart(void) const
{
	return (this->_intPart);
}

float	Fixed::getFracPart(void) const
{
	return (this->_fracPart);
}

int		Fixed::getRawBits(void) const
{
	return (this->_intPart + this->_fracPart);
}

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & i)
{
	o << i.getIntPart() + i.getFracPart();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fracPart = rhs.getFracPart();
	this->_intPart = rhs.getIntPart();
	this->_float = rhs._float;
	return *this;
}

/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(float const f) : _float(f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setIntPart(f);
	this->setFracPart(f);
}

Fixed::Fixed(int const n) : _float(n), _intPart(n), _fracPart(0)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(void) : _float(0), _intPart(0), _fracPart(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************ */
/* ******************** STATIC ******************** */

const int Fixed::_prec = 8;

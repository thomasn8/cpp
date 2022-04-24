#include "Fixed.hpp"

const int Fixed::_prec = 8;

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & num)
{
	o << num.getTypedValue();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs.getRawBits();
	return *this;
}


/* ******************************************************* */
/* ******************** GETTER/SETTER ******************** */

// initialise la valeur du nombre à virgule fixe
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// retourne la valeur du nombre à virgule fixe sans la convertir
int		Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}


/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::Fixed(float const num)
{
	this->setRawBits(0);
	this->_rawBits = this->toRawBits(num);
}

Fixed::Fixed(int const num)
{
	this->setRawBits(0);
	this->_rawBits = this->toRawBits(num);
}

Fixed::Fixed(void)
{
	this->setRawBits(0);
}

Fixed::~Fixed(void)
{
}

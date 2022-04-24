#include "Fixed.hpp"

/* ******************************************************* */
/* ******************** GETTER/SETTER ******************** */

// initialise la valeur du nombre à virgule fixe
void 			Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// retourne la valeur du nombre à virgule fixe sans la convertir
int				Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & num)
{
	o << num.getTypedValue();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}


/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(0);
	this->_rawBits = this->floatToRawBits(num);
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(0);
	this->_rawBits = this->intToRawBits(num);
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


/* ************************************************ */
/* ******************** STATIC ******************** */

const int Fixed::_prec = 8;

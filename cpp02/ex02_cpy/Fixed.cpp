#include "Fixed.hpp"

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & num)
{
	std::string rawBits;
	int			len;

	rawBits = num.decToBin(num.getRawBits());
	len = rawBits.length();
	rawBits.erase(0, len - 8);	
	if (rawBits == "00000000")
		o << num.toInt();
		// o << num.toInt() << "-" << num.getRawBits();
	else
		o << num.toFloat();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs._rawBits;
	return *this;
}


/* ******************************************************* */
/* ******************** GETTER/SETTER ******************** */

// initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
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

// convertit le float en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(float const num)
{
	this->setRawBits(Fixed::_initValue);
	this->_rawBits = this->floatToRawBits(num);
}

// convertit l'entier en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(int const num)
{
	this->setRawBits(Fixed::_initValue);
	this->_rawBits = this->intToRawBits(num);
}

// _initValue = 11111111 (8 x 1), considéré comme Null
Fixed::Fixed(void)
{
	this->setRawBits(Fixed::_initValue);
}

Fixed::~Fixed(void)
{
}

const int Fixed::_prec = 8;
const int Fixed::_initValue = 11111111;

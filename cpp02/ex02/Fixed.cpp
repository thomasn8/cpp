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

int 	Fixed::toInt(void) const
{
	return this->getIntPart();
}

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
	(void) raw;
	this->_fixed = this->_intPart + this->_fracPart;
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
	return (this->_fixed);
}

float	Fixed::getFixed(void) const
{
	return (this->_fixed);
}

float	Fixed::getFloat(void) const
{
	return (this->_float);
}


/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & i)
{
	o << i.getFixed();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	this->_fracPart = rhs.getFracPart();
	this->_intPart = rhs.getIntPart();
	this->_float = rhs._float;
	this->_fixed = rhs._fixed;
	return *this;
}

Fixed			Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->_float + rhs.getFloat());
}

Fixed			Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->_float - rhs.getFloat());
}

Fixed			Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->_float * rhs.getFloat());
}

Fixed			Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->_float / rhs.getFloat());
}

bool			Fixed::operator>(Fixed const & rhs) const
{
	if (this->_float > rhs.getFloat())
		return true;
	return false;
}

bool			Fixed::operator>=(Fixed const & rhs) const
{
	if (this->_float >= rhs.getFloat())
		return true;
	return false;
}

bool			Fixed::operator<(Fixed const & rhs) const
{
	if (this->_float < rhs.getFloat())
		return true;
	return false;
}

bool			Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_float <= rhs.getFloat())
		return true;
	return false;
}

bool			Fixed::operator==(Fixed const & rhs) const
{
	if (this->_float == rhs.getFloat())
		return true;
	return false;
}

bool			Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_float != rhs.getFloat())
		return true;
	return false;
}

Fixed			Fixed::operator++(void)
{
	this->setIntPart(this->_intPart++);
	this->setFracPart(this->_fracPart++);
	this->setRawBits(0);
	this->_float++;
	return *this;
}

Fixed			Fixed::operator++(int)
{
	Fixed	tmp(this->_float - 1);

	this->setIntPart(this->_intPart++);
	this->setFracPart(this->_fracPart++);
	this->setRawBits(0);
	this->_float++;
	return (tmp);
}

Fixed			Fixed::operator--(void)
{
	this->setIntPart(this->_intPart--);
	this->setFracPart(this->_fracPart--);
	this->setRawBits(0);
	this->_float--;
	return *this;
}

Fixed			 Fixed::operator--(int)
{
	Fixed	tmp(this->_float + 1);

	this->setIntPart(this->_intPart--);
	this->setFracPart(this->_fracPart--);
	this->setRawBits(0);
	this->_float--;
	return (tmp);
}

Fixed			Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs < rhs)
		return Fixed(lhs);
	else if (lhs > rhs)
		return Fixed(rhs);
	return (Fixed());
}

Fixed			Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs < rhs)
		return Fixed(lhs);
	else if (lhs > rhs)
		return Fixed(rhs);
	return (Fixed());
}

Fixed			Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs > rhs)
		return Fixed(lhs);
	else if (lhs < rhs)
		return Fixed(rhs);
	return (Fixed());
}

Fixed			Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs > rhs)
		return Fixed(lhs);
	else if (lhs < rhs)
		return Fixed(rhs);
	return (Fixed());
}


/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::Fixed(float const f) : _float(f)
{
	this->setIntPart(f);
	this->setFracPart(f);
	this->setRawBits((int)f);
}

Fixed::Fixed(int const n) : _float(n), _intPart(n), _fracPart(0), _fixed(n)
{
}

Fixed::Fixed(void) : _float(0), _intPart(0), _fracPart(0), _fixed(0)
{
}

Fixed::~Fixed(void)
{
}


/* ************************************************ */
/* ******************** STATIC ******************** */

const int Fixed::_prec = 8;

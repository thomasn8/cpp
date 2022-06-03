#include "Fixed.hpp"

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

Fixed			Fixed::operator+(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	return Fixed(l + r);
}

Fixed			Fixed::operator-(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	return Fixed(l - r);
}

Fixed			Fixed::operator*(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	return Fixed(l * r);
}

Fixed			Fixed::operator/(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	return Fixed(l / r);
}

bool			Fixed::operator>(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l > r)
		return true;
	return false;
}

bool			Fixed::operator>=(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l >= r)
		return true;
	return false;
}

bool			Fixed::operator<(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l < r)
		return true;
	return false;
}

bool			Fixed::operator<=(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l <= r)
		return true;
	return false;
}

bool			Fixed::operator==(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l == r)
		return true;
	return false;
}

bool			Fixed::operator!=(Fixed const & rhs) const
{
	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	if (l != r)
		return true;
	return false;
}

Fixed			Fixed::operator++(void)
{
	++this->_rawBits;
	return *this;
}

Fixed			Fixed::operator++(int)
{
	Fixed	tmp(this->toFloat());
	this->_rawBits++;
	return (tmp);
}

Fixed			Fixed::operator--(void)
{
	--this->_rawBits;
	return *this;
}

Fixed			 Fixed::operator--(int)
{
	Fixed	tmp(this->toFloat());
	this->_rawBits--;
	return (tmp);
}


/* ************************************************ */
/* ******************** STATIC ******************** */

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

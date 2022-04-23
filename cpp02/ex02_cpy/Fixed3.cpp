#include "Fixed.hpp"

/* *************************************************** */
/* ******************** SURCHARGE ******************** */

Fixed			Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed			Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed			Fixed::operator*(Fixed const & rhs) const
{
	// float is 5.04688
	// calc is 5.04688*2 = 10.0938

	// float is 5.05078
	// calc is 5.05078*2 = 10.1016

	float l = this->getTypedValue();
	float r = rhs.getTypedValue();
	// std::cout << "calc is " << l << "*" << r << " = " << l * r << std::endl;
	return Fixed(l * r);
}

Fixed			Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool			Fixed::operator>(Fixed const & rhs) const
{
	if (this->toFloat() > rhs.toFloat())
		return true;
	return false;
}

bool			Fixed::operator>=(Fixed const & rhs) const
{
	if (this->toFloat() >= rhs.toFloat())
		return true;
	return false;
}

bool			Fixed::operator<(Fixed const & rhs) const
{
	if (this->toFloat() < rhs.toFloat())
		return true;
	return false;
}

bool			Fixed::operator<=(Fixed const & rhs) const
{
	if (this->toFloat() <= rhs.toFloat())
		return true;
	return false;
}

bool			Fixed::operator==(Fixed const & rhs) const
{
	if (this->toFloat() == rhs.toFloat())
		return true;
	return false;
}

bool			Fixed::operator!=(Fixed const & rhs) const
{
	if (this->toFloat() != rhs.toFloat())
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

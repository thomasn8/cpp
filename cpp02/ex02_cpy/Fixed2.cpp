#include "Fixed.hpp"

std::string	Fixed::itoa(int const num) const
{
	std::stringstream	out;
	out << num;
	return out.str();
}

std::string	Fixed::itoaf(float const num) const
{
	std::stringstream	out;
	out << num;
	return out.str();
}

/* ************************************************** */
/* ******************** INTEGRAL ******************** */

std::string	Fixed::integralToBits(int num) const
{
	int			r;
	std::string bits;

	while (num)
	{
		r = num % 2;
		if (r == 1)
			bits = '1' + bits;
		else
			bits = '0' + bits;
		num /= 2;
	}
	// if (bits.length() == 0)
	// 	bits += '0';
	return bits;
}

/* ************************************************* */
/* ******************** DECIMAL ******************** */

float		Fixed::getDecimal(float const num) const
{
	std::string	s;
	float		r;

	s = itoaf(num);
	s = s.erase(0, s.find('.', 0));
	s = '0' + s;
	r = std::stof(s, NULL);
	return r;
}

std::string Fixed::decimalToBits(float num, int prec) const
{
	std::string bits;

	while (--prec >= 0)
	{
		if (num < 1)
			num *= 2;
		else
			num = (num - 1) * 2;
		if (num < 1)
			bits += '0';
		else
			bits += '1';
		// if (num == 1)
		// 	break;
	}
	return bits;
}

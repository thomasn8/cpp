#include "Fixed.hpp"

std::string	itoa(int num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

std::string	itoaf(float num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

/* ************************************************** */
/* ******************** INTEGRAL ******************** */

std::string	Fixed::integralToBits(int const num) const
{
	int			n;
	int			r;
	std::string bits;

	while (n)
	{
		r = n % 2;
		if (r == 1)
			bits += '1';
		else
			bits += '0';
		n /= 2;
	}
	if (bits.length() == 0)
		bits += '0';
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

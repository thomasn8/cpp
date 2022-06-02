#include "Fixed.hpp"

/* *********************************************** */
/* ******************** UTILS ******************** */

std::string	itoa(int const num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

std::string	itoaf(float const num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

float		Fixed::getDecimal(float const num) const
{
	std::string	s;
	float		r;

	s = itoaf(num);
	s = s.erase(0, s.find('.', 0));
	s = '0' + s;
	r = atof(s.c_str());
	return r;
}

int 	Fixed::toInt(int const num) const
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	int			res;
	int			prec = this->_prec;

	bits = this->decToBin(num);
	len = bits.length();
	if (num == 0 || len <= prec)
		return 0;
	len = bits.length();
	bits.erase(len - prec, prec);
	len = bits.length();
	res = 0;
	for (int e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-1-e);
	}
	return res;
}

float	Fixed::toFloat(int	const num) const 
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	float		res;
	int			prec = this->_prec;

	bits = this->decToBin(num);
	res = this->toInt(num);
	len = bits.length();
	if (len > prec)
		bits.erase(0, len - prec);
	len = bits.length();
	while (len != prec)
	{
		bits = '0' + bits;
		len = bits.length();
	}
	for (int e = 0; e < prec; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, -(e+1));
	}
	return res;
}

#include "Fixed.hpp"

/* ******************************************************* */
/* ******************** PRIVATE UTILS ******************** */

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
	r = std::stof(s, NULL);
	return r;
}

std::string	Fixed::decToBin(int num) const
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
	return bits;
}

std::string Fixed::decToBinFractPart(float num, int prec) const
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
	}
	return bits;
}

int 	Fixed::toInt(int const num) const
{
	std::string	bits;
	std::size_t	len = 0;
	char		b;
	int			bit;
	int			res;

	bits = this->decToBin(num);
	if (bits == "11111111" || bits.length() < 8)
		return 0;
	len = bits.length();
	bits.erase(len - 8, 8);
	len = bits.length();
	res = 0;
	for(size_t e = 0; e < len; e++)
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
	std::string	intBits;
	std::size_t	len;
	char		b;
	int			bit;
	float		res;

	bits = this->decToBin(num);
	if (bits == "11111111")
		return 0;
	res = this->toInt(num);
	len = bits.length();
	if (len > 8)
		bits.erase(0, len - 8);
	len = bits.length();
	while (len != 8)
	{
		bits = '0' + bits;
		len = bits.length();
	}
	for(int e = 0; e < 8; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, -(e+1));
	}
	return res;
}

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

float		getDecimal(float const num)
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

std::string decToBinFractPart(float num, int prec)
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

/* **************************************************** */
/* ******************** DEC TO BIN ******************** */

int		Fixed::intToRawBits(int const num) const
{
	std::string	rawBits;
	char		b;
	int			bit;
	size_t		len;
	int			res;
	int			prec = this->_prec;
	
	rawBits = this->decToBin(num);
	rawBits += "00000000";
	len = rawBits.length();
	res = 0;
	for(size_t e = 0; e < len; e++)
	{
		b = rawBits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-e-1);
	}
	return res;
}

int		Fixed::floatToRawBits(float const num) const
{
	std::string	rawBits;
	char		b;
	int			bit;
	size_t		len;
	int			res;
	int			prec = this->_prec;
	
	rawBits = this->decToBin((int)num);
	rawBits = rawBits + decToBinFractPart(getDecimal(num), prec);
	len = rawBits.length();
	res = 0;
	for(size_t e = 0; e < len; e++)
	{
		b = rawBits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-e-1);
	}
	return res;
}

/* **************************************************** */
/* ******************** BIN TO DEC ******************** */

int 	Fixed::toInt(void) const
{
	std::string	bits;
	std::size_t	len = 0;
	char		b;
	int			bit;
	int			res;
	int			prec = this->_prec;

	bits = this->decToBin(this->_rawBits);
	if (bits.length() < prec ||
		this->_rawBits == this->_initValue)
		return 0;
	len = bits.length();
	bits.erase(len - prec, prec);
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

float	Fixed::toFloat(void) const
{
	std::string	bits;
	std::string	intBits;
	std::size_t	len;
	char		b;
	int			bit;
	float		res;
	int			prec = this->_prec;

	if (this->_rawBits == this->_initValue)
		return 0;
	res = toInt();
	bits = this->decToBin(this->_rawBits);
	len = bits.length();
	if (len > prec)
		bits.erase(0, len - prec);
	len = bits.length();
	while (len != prec)
	{
		bits = '0' + bits;
		len = bits.length();
	}
	for(int e = 0; e < prec; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, -(e+1));
	}
	// ajustement de l'erreur absolue à + 2^(-n)
	// (aussi possible de ne pas le faire, c'est +- delta)
	// res += 1 * powf(2, -prec);
	return res;
}

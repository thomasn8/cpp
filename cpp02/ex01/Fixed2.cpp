#include "Fixed.hpp"

/* **************************************************** */
/* ******************** VALUE TYPE ******************** */

bool		Fixed::isFloat(void) const
{
	std::string	bits;
	int			len;
	int			i;

	if (this->_rawBits == 0)
		return false;
	bits = this->decToBin(this->_rawBits);
	len = bits.length();
	i = -1;
	while (len && ++i < this->_prec)
	{
		if (bits[len-1] == '1')
			return true;
		len--;
	}
	return false;
}

float		Fixed::getTypedValue(void) const
{
	if (this->isFloat())
		return (this->toFloat());
	else
		return (this->toInt());
}


/* **************************************************** */
/* ******************** DEC TO BIN ******************** */

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

// avec correction de +1 sur la valeur binaire 
// si trop grosse perte de précision par rapport au num initial
int		Fixed::toRawBits(float const num) const
{
	std::string	bits;
	char		b;
	int			bit;
	int			len;
	int			res;
	int			prec = this->_prec;
	float		correction;
	
	bits = this->decToBin((int)num);
	bits = bits + this->decToBinFractPart(this->getDecimal(num), prec);
	len = bits.length();
	res = 0;
	for (int e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-e-1);
	}
	correction = num - this->toFloat(res);
	if (correction > powf(2, -prec) / 2)
		res += 1;
	return res;
}


/* **************************************************** */
/* ******************** BIN TO DEC ******************** */

int 	Fixed::toInt(void) const
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	int			res;
	int			prec = this->_prec;

	bits = this->decToBin(this->_rawBits);
	len = bits.length();
	if (this->_rawBits == 0 || len <= prec)
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

float	Fixed::toFloat(void) const
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	float		res;
	int			prec = this->_prec;

	bits = this->decToBin(this->_rawBits);
	res = toInt();
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

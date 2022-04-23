#include "Fixed.hpp"

std::string	decToBin(int num)
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

int 	toInt2(int const num)
{
	std::string	bits;
	std::size_t	len = 0;
	char		b;
	int			bit;
	int			res;

	bits = decToBin(num);
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

float	toFloat2(int	const num)
{
	std::string	bits;
	std::string	intBits;
	std::size_t	len;
	char		b;
	int			bit;
	float		res;

	bits = decToBin(num);
	if (bits == "11111111")
		return 0;
	res = toInt2(num);
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
	float		correction;
	
	// std::cout << "FLOAT is " << num << std::endl;
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
	// std::cout << "RES is " << res << "(" << toFloat2(res)<< ")" <<std::endl;
	// std::cout << "CORRECTION: " << num << " - " << toFloat2(res) << " = " << num - toFloat2(res) <<std::endl;
	// std::cout << "Half precsion = " << powf(2, -prec) / 2 << std::endl;
	correction = num - toFloat2(res);
	if (correction > powf(2, -prec) / 2)
		res += 1;
	// std::cout << "RES AFTER CORRECTION is " << res <<std::endl;
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
	if (bits.length() < prec || this->_rawBits == 0)
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

	if (this->_rawBits == 0)
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
	return res;
}


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
		// return (this->toFloat() + powf(2, -(this->_prec)));
	else
		return (this->toInt());
}

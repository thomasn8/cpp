#include "Fixed.hpp"

/* ******************** Calcules de conversion ******************** */

std::string itoa(float num)
{
	std::stringstream	out;
	out << num;
	return (out.str());
}

float	Fixed::calcFracPart(float num) const
{
	std::string	s;
	float		r;

	s = itoa(num);
	s = s.erase(0, s.find('.', 0));
	s = '0' + s;
	r = std::stof(s, NULL);
	return r;
}

std::string Fixed::calcBits(float f, int prec) const
{
	std::string bits;

	while (--prec >= 0)
	{
		if (f < 1)
			f *= 2;
		else
			f = (f - 1) * 2;
		if (f < 1)
			bits += '0';
		else
			bits += '1';
		if (f == 1)
			break;
	}
	return bits;
}

// ENLEVER LES COMMENTAIRES POUR VOIR LES CALCULES ET L'AJUSTEMENT DE L'ERREUR ABSOLUE
float	Fixed::calcBitsToFloat(std::string bits, int prec) const
{
	float	res = 0;
	char	c;
	int		bit;
	int		e = 0;					// index dans la partie bits <-> donne l'exposant dans le calcul
	int		len = bits.length();

	// std::cout << std::endl <<std::endl << "CALC:" << std::endl;
	while (e < prec && e < len)
	{
		c = bits[e];
		bit = atoi(&c);
		// std::cout << res << " += " << bit << " * 2^" << -(e+1) << std::endl;
		res += bit * powf(2, -(e+1));
		e++;
	}
	if (e == 8)
	{
		res += 1 * powf(2, -prec);	// ajustement de l'erreur absolue à + 2^(-n)
	}
	// std::cout << "fixed<,8> = " << res;
	// std::cout << std::endl << std::endl << std::endl;
	return res;
}

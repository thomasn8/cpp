#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>

std::string itoa(float num)
{
	std::stringstream	out;
	out << num;
	return (out.str());
}

float	get_remind(float num)
{
	std::string	s;
	float		r;

	s = itoa(num);
	s = s.erase(0, s.find('.', 0));
	s = '0' + s;
	r = std::stof(s, NULL);
	return r;
}

std::string get_bits(float f, int prec)
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
	std::cout << "bitsraw = " << bits << std::endl; 
	return bits;
}

float	bits_to_float(std::string bits, int prec)
{
	float	res = 0;
	char	c;
	int		bit;
	int		e = 0;		// index dans la partie bits <-> donne l'exposant dans le calcul
	int		len = bits.length();

	while (e < prec && e < len)
	{
		c = bits[e];
		bit = atoi(&c);
		std::cout << res << " += " << bit << " * 2^" << -(e+1) << std::endl; 
		res += bit * powf(2, -(e+1));
		e++;
	}
	if (e == 8)
		res += 1 * powf(2, -prec);	// ajustement de l'erreur absolue à + 2^(-n)
	return res;
}

std::string	fract_bits(float num, int prec)
{
	float		f;
	std::string bits;
	float		res;

	f = get_remind(num);
	bits = get_bits(f, prec);
	res = bits_to_float(bits, prec);
	std::cout << "Res: " << (int)num << " + " << res << " = " <<(int)num + res << std::endl << std::endl;
	return bits;
}

int main()
{
	// fract_bits(1234.4321, 8);
	fract_bits(42.42, 8);
	// fract_bits(10.1, 8);
	// fract_bits(6.75, 8);
	std::cout << "Res2:" << roundf(42.42) << std::endl;
	return 0;
}

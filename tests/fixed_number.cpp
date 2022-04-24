#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

// global var permettant de préciser 
// la longueur des calcules binaires
// pour stocker la partie fractionnaire du float
int	g_prec = 8;

/* **************************************************** */
/* *************** CALCULS DE CONVERSION ************** */

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

std::string floatDecToBin(float num, int prec)
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
/* ******************** BIN TO DEC ******************** */

int 	toInt(int const num)
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	int			res;

	bits = decToBin(num);
	len = bits.length();
	if (num == 0 || len <= g_prec)
		return 0;
	len = bits.length();
	bits.erase(len - g_prec, g_prec);
	len = bits.length();
	res = 0;
	for(int e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-1-e);
	}
	return res;
}

float	toFloat(int	const num)
{
	std::string	bits;
	int			len;
	char		b;
	int			bit;
	float		res;

	bits = decToBin(num);
	res = toInt(num);
	len = bits.length();
	if (len > g_prec)
		bits.erase(0, len - g_prec);
	len = bits.length();
	while (len != g_prec)
	{
		bits = '0' + bits;
		len = bits.length();
	}
	for(int e = 0; e < g_prec; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, -(e+1));
	}
	return res;
}


/* **************************************************** */
/* ******************** DEC TO BIN ******************** */

// avec correction de +1 sur la valeur binaire 
// si trop grosse perte de précision par rapport au float initial
int		toRawBits(float const num)
{
	std::string	bits;
	char		b;
	int			bit;
	int			len;
	int			res;
	float 		correction;

	bits = decToBin((int)num);
	bits = bits + floatDecToBin(getDecimal(num), g_prec);
	len = bits.length();
	res = 0;
	for(int e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, len-e-1);
	}
	correction = num - toFloat(res);
	if (correction > powf(2, -g_prec) / 2)
		res += 1;
	return res;
}

void	int_conversions(float n)
{
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n = toRawBits(n);
	std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	n = toInt(n);
	std::cout << std::endl;
}

void	float_conversions(float n)
{
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
}


/* 
	// PLUS ON AUGMENTE LA PRECISION, MOINS ON A DE BITS DISPO POUR STOCKER LE NOMBRE
	// -> exemple: sur 8 bits de précision on peut traiter un float comme 1234.43
	// mais pas sur 12 bits de précision
	

	// POUR UNE PRECISION SUR 8 BITS:
	
	En 32 bits: max int = 2147483647 = 1111111111111111111111111111111 -> 31 bits (+1 pour le signe)
	Ici on a 26 bits pour stocker la partie intégrale, 8 réservés au décimale (initialisés à '11111111')
	
	Max int dans ce système à 26 bits = 8388607 = 11111111111111111111111
	On peut voir que 8388608 donne en binaire:    100000000000000000000000

	8388607 -> en bits -> 11111111111111111111111.00000000  -> on utilise 31 bits, max
	8388608 -> en bits -> 100000000000000000000000.00000000 -> on utilise 32 bits, 1 de trop
*/
int main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cout << "Usage: ./a.out precision num_1 ... num_n" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		if ((atof(av[i]) == 0) && strcmp(av[i], "0") != 0)
		{
			std::cout << "Error: arguments must be numbers only" << std::endl;
			return 1;
		}
	}
	g_prec = atoi(av[1]);
	std::cout << std::endl;
	std::cout << "****** TO INT ******" << std::endl;
	for (int i = 2; i < ac; i++)
		int_conversions(atof(av[i]));
	std::cout << "****** TO FLOAT ******" << std::endl;
	for (int i = 2; i < ac; i++)
		float_conversions(atof(av[i]));


	// int  t = -1;
	// /* ************************** */
	// /* ****** BIT PAR BIT  ****** */
	// while (++t < 5)
	// 	std::cout << std::endl << "toFloat(" << t << "): " << std::endl << toFloat(t) << std::endl;
	// std::cout << std::endl;


	// float	n;
	// /* ******************** */
	// /* ****** TO INT ****** */
	// std::cout << "****** TO INT ******" << std::endl;
	// n = 42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 42.42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 0.42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 0.78;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 0;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 5;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 5.05;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;
	// n = 1234.4321;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toInt() = " << toInt(n) << std::endl;
	// n = toInt(n);
	// std::cout << std::endl;

	// // /* ********************** */
	// // /* ****** TO FLOAT ****** */
	// std::cout << std::endl << std::endl << "****** TO FLOAT ******" << std::endl;
	// n = 42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 42.42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 0.42;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 0.78;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 5;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 5.05;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 0;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 1234.4321;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 0.00390625;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;
	// n = 0.0078125;
	// std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	// n=toRawBits(n);
	// std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	// n = toFloat(n);
	// std::cout << std::endl;

	return 0;
}

/* 	WHAT HAPPEN ?

		// Conversion:
	// 42 -> en bits -> 101010.00000000
	// 10101000000000 -> en int -> 10752
		// Déconversion:
	// 10752 -> en bits -> 10101000000000
	// 101010.00000000 -> en int -> 101010.00000000
		// -> 101010 -> 42
		// -> 00000000 -> 0
		// -> 42

		// Conversion:
	// 42.42 -> en bits -> 101010.01101011
	// 10101001101011 -> en int -> 10859
		// Déconversion:
	// 10859 -> en bits -> 10101001101011
	// 101010.01101011 -> en int -> 101010.00000000
		// -> 101010 -> 42
		// -> 00000000 -> 0
		// -> 42

		// Conversion:
	// 42.42 -> en bits -> 101010.01101011
	// 10101001101011 -> en int -> 10859
		// Déconversion:
	// 10859 -> en bits -> 10101001101011
	// 101010.01101011 -> en float -> 101010.01101011
		// -> 101010 -> 42
		// -> 01101011 -> 0.4219
		// -> 42.4219

		// Conversion:
	// 0.42 -> en bits -> .01101011
	// 1101011 -> en int -> 107
		// Déconversion:
	// 107 -> en bits -> 1101011
	// .01101011 -> en float -> 0.01101011
		// -> 0 -> 0
		// -> .01101011 -> 0.4219
		// -> 0.4219

		// Conversion:
	// 0.00390625-> en bits -> .00000001
	// 000000001 -> en int -> 1
		// Déconversion:
	// 1 -> en bits -> 00000001
	// 00000001 -> en float -> 0.00000001
		// -> 0 -> 0
		// -> 00000001 -> 0.00390625
		// -> 0.00390625
*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

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

/* **************************************************** */
/* ******************** DEC TO BIN ******************** */

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
	
	// std::cout << std::endl; 
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
		// std::cout << "bits = " << bits << std::endl; 
	}
	// std::cout << "bits = " << bits << std::endl; 
	return bits;
}

int		toRawBits(float const num)
{
	std::string	rawBits;
	char		b;
	int			bit;
	size_t		len;
	int			res;
	
	// std::cout << std::endl; 
	rawBits = decToBin((int)num);
	// std::cout << "rawBits1: " << rawBits << std::endl; 
	rawBits = rawBits + floatDecToBin(getDecimal(num), 8);
	// std::cout << "rawBits2: " << rawBits << std::endl; 
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

int 	toInt(int const num)
{
	std::string	bits;
	std::size_t	len = 0;
	char		b;
	int			bit;
	int			res;

// std::cout << std::endl << std::endl << "toInt()" << std::endl;
// std::cout << num << std::endl;
	bits = decToBin(num);
// std::cout << bits << std::endl;
	if (bits == "11111111" || bits.length() < 8)
		return 0;
	len = bits.length();
	bits.erase(len - 8, 8);
	len = bits.length();
// std::cout << bits << std::endl;
	res = 0;
	for(size_t e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
// std::cout << bit << "* 2^" << len-1-e << std::endl;
		res += bit * powf(2, len-1-e);
	}
// std::cout << res << std::endl;
	return res;
}

float	toFloat(int	const num)
{
	std::string	bits;
	std::string	intBits;
	std::size_t	len;
	char		b;
	int			bit;
	float		res;

	bits = decToBin(num);
// std::cout << "bits: "<< bits << std::endl;
	if (bits == "11111111")
		return 0;
	res = toInt(num);
// if (res)
// std::cout << "int res: "<< res << std::endl;
	len = bits.length();
	if (len > 8)
		bits.erase(0, len - 8);
// std::cout << "bits: "<< bits << std::endl;
	len = bits.length();
	while (len != 8)
	{
		bits = '0' + bits;
		len = bits.length();
	}
// std::cout << "bits: "<< bits << std::endl;
	for(int e = 0; e < 8; e++)
	{
		b = bits[e];
		bit = atoi(&b);
// std::cout << bit << " * 2^" << -(e+1);
		res += bit * powf(2, -(e+1));
// std::cout << " = " << bit * powf(2, -(e+1)) << std::endl;
	}
// std::cout << "+ " << 1 * powf(2, -8) << std::endl;
	res += 1 * powf(2, -8);	// ajustement de l'erreur absolue à + 2^(-n), possible de ne pas le faire aussi
// std::cout << "Résultat = ";
	return res;
}

/* 
	En 32 bits: max int = 2147483647 = 1111111111111111111111111111111 -> 31 bits (+1 pour le signe)
	Ici on a 26 bits pour stocker la partie intégrale, 8 réservés au décimale (initialisés à '11111111')
	
	Max int dans ce système à 26 bits = 8388607 = 11111111111111111111111
	On peut voir que 8388608 donne en binaire:    100000000000000000000000

	8388607 -> en bits -> 11111111111111111111111.00000000  -> on utilise 31 bits, max
	8388608 -> en bits -> 100000000000000000000000.00000000 -> on utilise 32 bits, 1 de trop
*/
int main()
{
	int  t = -1;
	while (++t < 5)
		std::cout << std::endl << "toFloat(" << t << "): " << std::endl << toFloat(t) << std::endl;

	float	n;

	/* ******************** */
	/* ****** TO INT ****** */
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

	/* ********************** */
	/* ****** TO FLOAT ****** */
	std::cout << std::endl << std::endl << "****** TO FLOAT ******" << std::endl;
	n = 42;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 42.42;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 0.42;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 0.78;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 5.05;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 0;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 1234.4321;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 0.00390625;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;
	n = 0.0078125;
	std::cout << "conversion de " << n << " toRawBits() = " << toRawBits(n) << std::endl;
	n=toRawBits(n);
	std::cout << "déconversion de " << n << " toFloat() = " << toFloat(n) << std::endl;
	n = toFloat(n);
	std::cout << std::endl;

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

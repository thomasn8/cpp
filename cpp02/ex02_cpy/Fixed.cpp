#include "Fixed.hpp"

/* ***************************************************** */
/* ******************** CONVERSIONS ******************** */

// convertit un nombre (int ou float) en _rawBits
int		Fixed::toRawBits(float const num) const
{
	std::string	int_bits;
	std::string	dec_bits;
	std::string	combine;
	int			rawBits;
	
	int_bits = integralToBits((int)num);
	dec_bits = decimalToBits(this->getDecimal(num), this->_prec);
	combine = int_bits + dec_bits;
	// ici on a qqch comme: 10011.11000000
	// la partie intégrale peut varier en taille: 		IIII.	ou	II.
	// et la partie décimale est forcément sur 8 bits:	.DDDDDDDD
	
	rawBits = atoi(combine.c_str());
	// au finale on peut avoir qqch comme IIIIDDDDDDDD
	// on saura que les 8 derniers bits représentent la partie décimale.
	// tout ce qui est avant représente la partie intégrale
	return rawBits;
}


/* ******************************************************* */
/* ******************** DECONVERSIONS ******************** */

// // ENLEVER LES COMMENTAIRES POUR VOIR LES CALCULES ET L'AJUSTEMENT DE L'ERREUR ABSOLUE
// float		Fixed::bitsToFloat(std::string bits, int prec) const
// {
// 	float	res = 0;
// 	char	c;
// 	int		bit;
// 	int		e = 0;					// index dans la partie bits <-> donne l'exposant dans le calcul
// 	int		len = bits.length();

// 	// std::cout << std::endl <<std::endl << "CALC:" << std::endl;
// 	while (e < prec && e < len)
// 	{
// 		c = bits[e];
// 		bit = atoi(&c);
// 		// std::cout << res << " += " << bit << " * 2^" << -(e+1) << std::endl;
// 		res += bit * powf(2, -(e+1));
// 		e++;
// 	}
// 	if (e == 8)
// 	{
// 		res += 1 * powf(2, -prec);	// ajustement de l'erreur absolue à + 2^(-n)
// 	}
// 	// std::cout << "fixed<,8> = " << res;
// 	// std::cout << std::endl << std::endl << std::endl;
// 	return res;
// }

// déconvertit _rawBits en nombre entier
int 	Fixed::toInt(void) const
{
	// itoa(rawBits)
	// on retire les 8 derniers char, car pas de decimal
	// on applique la formule de conversion de binaire à décimal pour int
}

// déconvertit _rawBits (valeur en virgule fixe) en float (nombre à virgule flottante)
float	Fixed::toFloat(void) const
{
	// itoa(rawBits)
	// on split le rawBits en 2: 
	// 8 derniers char = partie décimal -> formule de conversion de binaire à décimal pour decimal
	// restant = partie intégrale -> formule de conversion de binaire à décimal pour int
}


/* ******************************************************* */
/* ******************** GETTER/SETTER ******************** */

// initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// retourne la valeur du nombre à virgule fixe sans la convertir
int		Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}


/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

// convertit le float en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(float const num)
{
	this->setRawBits(Fixed::_initValue);
	this->_rawBits = this->toRawBits(num);
}

// convertit l'entier en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(int const num)
{
	this->setRawBits(Fixed::_initValue);
	this->_rawBits = this->toRawBits(num);
}

// _initValue = 11111111 (8 x 1), considéré comme Null
Fixed::Fixed(void)
{
	this->setRawBits(Fixed::_initValue);
}

Fixed::~Fixed(void)
{
}


/* *************************************************** */
/* ******************** SURCHARGE ******************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & num)
{
	o << num.toFloat();
	return o;
}

Fixed			& Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs._rawBits;
	return *this;
}

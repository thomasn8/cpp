#include "Fixed.hpp"

/* ***************************************************** */
/* ******************** CONVERSIONS ******************** */

// convertit un nombre (int ou float) en _rawBits
std::string		toRawBits(float const num) const
{
	std::string	int_bits;
	std::string	dec_bits;
	std::string	rawBits;
	
	int_bits = integralToBits((int)num);
	dec_bits = decimalToBits(this->getDecimal(num), this->_prec);
	rawBits = int_bits + dec_bits;
	return rawBits;
}

/* ******************************************************* */
/* ******************** DECONVERSIONS ******************** */

// déconvertit _rawBits en nombre entier
int 	Fixed::toInt(void) const
{
	std::string	bits = this->itoa(this->_rawBits);
	std::size_t	len = bits.length();
	char		b;
	int			bit;
	int			res = 0;
	
	// si rawBits ==  '11111111' -> return 0
	// si rawBits == '0DDDDDDDD' -> return 0 car correspond à 0.XXXXXX
	if (bits.length() == 8)
		return 0;

	// retire les 8 derniers char, car on veut retourner que la partie int part
	bits.erase (len - 4, len);

	// formule de conversion de binaire à décimal pour int
	for(size_t e = 0; e < len; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res += bit * powf(2, e);
	}
	return res;
}


// float		Fixed::bitsToFloat(std::string bits, int prec) const
// {
// 	float	res = 0;
// 	char	b;
// 	int		bit;
// 	int		e = 0;					// index dans la partie bits <-> donne l'exposant dans le calcul
// 	int		len = bits.length();

// 	// std::cout << std::endl <<std::endl << "CALC:" << std::endl;
// 	while (e < prec && e < len)
// 	{
// 		b = bits[e];
// 		bit = atoi(&b);
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

// déconvertit _rawBits (valeur en virgule fixe) en float (nombre à virgule flottante)
float	Fixed::toFloat(void) const
{
	std::string	bits = this->itoa(this->_rawBits);
	std::size_t	len = bits.length();
	char		b;
	int			bit;
	int			res_int = 0;
	float		res_dec = 0;

	// si rawBits == '11111111' -> return 0
	if (bits.length() == 8)
		return 0;
	
	res_int = this->toInt();
	
	// on garde que les 8 derniers chars
	bits.erase (0, len - 8);

	// formule de conversion de binaire à décimal pour decimal part
	// while (e < prec && e < len)
	for(size_t e = 0; e < this->_prec; e++)
	{
		b = bits[e];
		bit = atoi(&b);
		res_dec += bit * powf(2, -(e + 1));
	}
	// ajustement de l'erreur absolue à + 2^(-n)
	res_dec += 1 * powf(2, -this->_prec);

	return res_int + res_dec;
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
	this->_bits = this->toRawBits(num);
}

// convertit l'entier en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
Fixed::Fixed(int const num)
{
	this->setRawBits(Fixed::_initValue);
	this->_bits = this->toRawBits(num);
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

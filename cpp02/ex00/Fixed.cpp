#include "Fixed.hpp"

// accesseur: retourne la valeur du nombre à virgule fixe sans la convertir
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

// setter: initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbr = raw;
}

// affecteur (ou assignateur): modifie l'instance
Fixed	& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = rhs.getRawBits();
	return *this;
}

// constructeur par copie
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// constructeur par défaut
Fixed::Fixed(void) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// destructeur
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// initialisation d'une variable de classe constante
// (sert a indique le nombre de décimal commun à toute la classe, et immuable)
const int Fixed::_decimal = 8;

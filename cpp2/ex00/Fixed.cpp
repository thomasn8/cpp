#include "Fixed.hpp"

/* ******************************************************* */
/* ******************** GETTER/SETTER ******************** */

// initialise la valeur du nombre à virgule fixe
void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

// retourne la valeur du nombre à virgule fixe sans la convertir
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}


/* *************************************************** */
/* ******************** SURCHARGE ******************** */

// affecteur (ou assignateur): modifie l'instance
Fixed	& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}


/* ****************************************************** */
/* ******************** CONSTRUCTEUR ******************** */

// constructeur par copie: créer une nouvelle instance identique
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// constructeur par défaut
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// destructeur
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


/* ************************************************ */
/* ******************** STATIC ******************** */

// initialisation d'une variable de classe constante
// (sert a indique le nombre de décimal constant commun à toute la classe)
const int Fixed::_prec = 8;

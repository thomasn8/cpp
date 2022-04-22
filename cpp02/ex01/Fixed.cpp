#include "Fixed.hpp"

// accesseur: retourne la valeur du nombre à virgule fixe sans la convertir
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fracP);
}

// setter: initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
void Fixed::setIntPart(int const n)
{
	std::cout << "set integer decimal part" << std::endl;
	this->_intP = n;
}

// setter: initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fracP = raw;
}

// affecteur (ou assignateur): modifie l'instance
Fixed	& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fracP = rhs.getRawBits();
	return *this;
}

// constructeur par copie
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Un constructeur prenant un flottant constant en paramètre et qui convertit celui-ci en virgule fixe. 
Fixed::Fixed(float const n)
{
	int	intP;
	int	fracP;

	intP = this->convertIntPart(n);
	fracP = this->convertFracPart(n);
	this->setIntPart(intP);
	this->setRawBits(fracP);
	std::cout << "Float constructor called" << std::endl;
}

// Un constructeur prenant un entier constant en paramètre et qui convertit celui-ci en virgule fixe. 
Fixed::Fixed(int const n) : _fracP(0)
{
	std::cout << "Int constructor called" << std::endl;
}

// constructeur par défaut
Fixed::Fixed(void) : _fracP(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// destructeur
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// initialisation de la variable de classe constante définissant la précision des nbr a virgule fixe
const int Fixed::_fracBits = 8;

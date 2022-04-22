#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);

		Fixed	& operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	setIntPart(int const n);
		float	toFloat(void) const;
		int 	toInt(void) const;

		int		convertIntPart(float const n);
		int		convertFracPart(float const n);

	private:
		int _intP;						// partie intégrale en décimale
		int	_fracP;						// représentation binaire de la partie fractionnaire
		
		static const int _fracBits;		// représentation sur 8 bits. Exemple: 0,8 = 0,11001100
};

std::ostream	& operator<<(std::ostream & o, Fixed const & nbr);

/* ***************************************************************** */

std::ostream	& operator<<(std::ostream & o, Fixed const & i)
{
	std::cout << "Flux redirection operator called on " << o << ": ";
	o << i.getRawBits();
	return o;
}

int		Fixed::convertIntPart(float const n)
{

}

int		Fixed::convertFracPart(float const n)
{

}






// Une fonction membre qui convertit la valeur en virgule fixe en nombre entier.
int 	Fixed::toInt(void) const
{
	// convertir la valeur virgule fixe -> en nombre entier
}

// Une fonction membre qui convertit la valeur en virgule fixe en nombre à virgule flottante.
float	Fixed::toFloat(void) const
{
	// convertit la valeur virgule fixe -> en nombre à virgule flottante 
}


#endif

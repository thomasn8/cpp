#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>

/* 

Ajoutez à votre classe ces quatre fonctions membres publiques surchargées :

Min (normal/constant)
• Une fonction membre statique min prenant en paramètres deux références sur des
nombres à virgule fixe et qui retourne le plus petit d’entre eux.
• Une fonction membre statique min prenant en paramètres deux références sur des
nombres à virgule fixe constants et qui retourne le plus petit d’entre eux.

Max (normal/constant)
• Une fonction membre statique max prenant en paramètres deux références sur des
nombres à virgule fixe et qui retourne le plus grand d’entre eux.
• Une fonction membre statique max prenant en paramètres deux références sur des
nombres à virgule fixe constants et qui retourne le plus grand d’entre eux.
*/

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed(void);

		void		setRawBits(int const raw);
		void		setIntPart(float const f);
		void		setFracPart(float const f);
		int			getRawBits(void) const;
		int			getIntPart(void) const;
		float		getFracPart(void) const;
		float		getFloat(void) const;
		float		getFixed(void) const;

		float		toFloat(void) const;
		int 		toInt(void) const;
		float		convertFracPart(float const f) const;
		float		calcBitsToFloat(std::string bits, int prec) const;
		std::string calcBits(float f, int prec) const;
		float		calcFracPart(float num) const;

		
		Fixed		& operator=(Fixed const & rhs);
		
		bool		operator>(Fixed const & rhs) const;
		bool		operator>=(Fixed const & rhs) const;
		bool		operator<(Fixed const & rhs) const;
		bool		operator<=(Fixed const & rhs) const;
		bool		operator==(Fixed const & rhs) const;
		bool		operator!=(Fixed const & rhs) const;

		Fixed		operator+(Fixed const & rhs) const;
		Fixed		operator-(Fixed const & rhs) const;
		Fixed		operator*(Fixed const & rhs) const;
		Fixed		operator/(Fixed const & rhs) const;

		Fixed		operator++(void);
		Fixed		operator++(int);
		Fixed		operator--(void);
		Fixed		operator--(int);

		static Fixed	min(Fixed & lhs, Fixed & rhs);
		static Fixed	min(Fixed const & lhs, Fixed const & rhs);
		static Fixed	max(Fixed & lhs, Fixed & rhs);
		static Fixed	max(Fixed const & lhs, Fixed const & rhs);

	private:
		int			_rawBits;
		float		_float;
		int 		_intPart;
		float		_fracPart;
		float		_fixed;

		static const int _prec;
};

std::ostream	& operator<<(std::ostream & o, Fixed const & nbr);

#endif

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>

class Fixed
{
	public:
		void	setRawBits(int const raw);
		void	setIntPart(float const f);
		void	setFracPart(float const f);
		int		getRawBits(void) const;
		int		getIntPart(void) const;
		float	getFracPart(void) const;

		float		toFloat(void) const;
		int 		toInt(void) const;
		float		convertFracPart(float const f) const;
		float		calcBitsToFloat(std::string bits, int prec) const;
		std::string calcBits(float f, int prec) const;
		float		calcFracPart(float num) const;

		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed(void);
		
		Fixed	& operator=(Fixed const & rhs);

	private:
		int		_rawBits;
		float	_float;
		int 	_intPart;
		float	_fracPart;

		static const int _prec;
};

std::ostream	& operator<<(std::ostream & o, Fixed const & nbr);

#endif

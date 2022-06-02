#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

class Fixed
{
	public:

		// CANONICAL
		Fixed(Fixed const & src);
		Fixed(float const num);
		Fixed(int const num);
		Fixed(void);
		~Fixed(void);
		Fixed		& operator=(Fixed const & rhs);

		// SETTER/GETTER/CONVERTERS
		void		setRawBits(int const raw);
		int			getRawBits(void) const;
		float		getTypedValue(void) const;
		bool		isFloat(void) const;
		float		toFloat(void) const;
		int 		toInt(void) const;

	private:
		
		// CONVERTIT UN NOMBRE SUR _RAWBITS 
		// EN RESERVANT LES _PREC PREMIERS BITS 
		// POUR LA PRECISION DE LA PARTIE FRACTIONNAIRE DU NOMBRE
		int			toRawBits(float const num) const;

		// DATA/PRECISION
		int					_rawBits;
		static const int	_prec;

		// UTILS DANS LES CONVERTERS
		float		getDecimal(float const num) const;
		std::string	decToBin(int num) const;
		std::string decToBinFractPart(float num, int prec) const;
		float		toFloat(int	const num) const;
		int 		toInt(int const num) const;

};

std::ostream	& operator<<(std::ostream & o, Fixed const & num);

#endif


// #ifndef FIXED_HPP
// # define FIXED_HPP

// #include <iostream>
// #include <cmath>
// #include <sstream>
// #include <cstdlib>

// class Fixed
// {
// 	public:

// 		// CANONICAL
// 		Fixed(Fixed const & src);
// 		Fixed(float const num);
// 		Fixed(int const num);
// 		Fixed(void);
// 		~Fixed(void);
// 		Fixed		& operator=(Fixed const & rhs);
// 		// SETTER/GETTER/CONVERTERS
// 		void		setRawBits(int const raw);
// 		int			getRawBits(void) const;
// 		float		getTypedValue(void) const;
// 		bool		isFloat(void) const;
// 		float		toFloat(void) const;
// 		int 		toInt(void) const;

// 	private:

// 		// DATA/PRECISION
// 		int			_rawBits;
// 		static const int	_prec;
// 		// CONVERTERS DANS LES CONSTRUCTEURS
// 		int			intToRawBits(int const num) const;
// 		int			floatToRawBits(float const num) const;
// 		// UTILS DANS LES CONVERTERS
// 		float		getDecimal(float const num) const;
// 		std::string	decToBin(int num) const;
// 		std::string decToBinFractPart(float num, int prec) const;
// 		float		toFloat(int	const num) const;
// 		int 		toInt(int const num) const;

// };

// std::ostream	& operator<<(std::ostream & o, Fixed const & num);

// #endif

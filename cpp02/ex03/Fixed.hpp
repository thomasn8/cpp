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
		
		// SURCHARGES
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

		// DATA/PRECISION
		int			_rawBits;
		static const int	_prec;

		// CONVERTERS DANS LES CONSTRUCTEURS
		int			toRawBits(float const num) const;

		// UTILS DANS LES CONVERTERS
		float		getDecimal(float const num) const;
		std::string	decToBin(int num) const;
		std::string decToBinFractPart(float num, int prec) const;
		float		toFloat(int	const num) const;
		int 		toInt(int const num) const;

};

std::ostream	& operator<<(std::ostream & o, Fixed const & num);

#endif

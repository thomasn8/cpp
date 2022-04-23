#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

class Fixed
{
	public:
		Fixed(Fixed const & src);
		Fixed(float const num);
		Fixed(int const num);
		Fixed(void);
		~Fixed(void);

		Fixed		& operator=(Fixed const & rhs);

		void		setRawBits(int const raw);
		int			getRawBits(void) const;
		float		toFloat(void) const;
		int 		toInt(void) const;

		// CONVERSIONS
		std::string	toRawBits(float const num) const;
		// CONVERSION PARTIE INTEGRALE
		std::string	integralToBits(int num) const;
		float		convertIntPart(float const num) const;
		// CONVERSION PARTIE DECIMALE
		float		getDecimal(float const num) const;
		std::string decimalToBits(float num, int prec) const;
		// float		bitsToFloat(std::string bits, int prec) const;
		
		std::string	itoa(int const num) const;
		std::string	itoaf(float const num) const;

		
		// bool		operator>(Fixed const & rhs) const;
		// bool		operator>=(Fixed const & rhs) const;
		// bool		operator<(Fixed const & rhs) const;
		// bool		operator<=(Fixed const & rhs) const;
		// bool		operator==(Fixed const & rhs) const;
		// bool		operator!=(Fixed const & rhs) const;

		// Fixed		operator+(Fixed const & rhs) const;
		// Fixed		operator-(Fixed const & rhs) const;
		// Fixed		operator*(Fixed const & rhs) const;
		// Fixed		operator/(Fixed const & rhs) const;

		// Fixed		operator++(void);
		// Fixed		operator++(int);
		// Fixed		operator--(void);
		// Fixed		operator--(int);

		// static Fixed	min(Fixed & lhs, Fixed & rhs);
		// static Fixed	min(Fixed const & lhs, Fixed const & rhs);
		// static Fixed	max(Fixed & lhs, Fixed & rhs);
		// static Fixed	max(Fixed const & lhs, Fixed const & rhs);

	private:
		int					_rawBits;
		std::string			_bits;

		static const int	_prec;
		static const int	_initValue;
};

std::ostream	& operator<<(std::ostream & o, Fixed const & num);

#endif

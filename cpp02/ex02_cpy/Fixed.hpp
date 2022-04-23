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
		
		std::string	decToBin(int num) const;

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

		int			intToRawBits(int const num) const;
		int			floatToRawBits(float const num) const;

		static const int	_prec;
		static const int	_initValue;
};

std::ostream	& operator<<(std::ostream & o, Fixed const & num);

#endif

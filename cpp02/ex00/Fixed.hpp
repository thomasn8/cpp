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
		Fixed(void);
		~Fixed(void);
		Fixed		& operator=(Fixed const & rhs);

		// SETTER/GETTER/CONVERTERS
		void		setRawBits(int const raw);
		int			getRawBits(void) const;

	private:

		// DATA/PRECISION
		int			_rawBits;
		static const int	_prec;

};

std::ostream	& operator<<(std::ostream & o, Fixed const & num);

#endif

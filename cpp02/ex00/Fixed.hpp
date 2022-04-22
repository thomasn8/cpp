#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed	& operator=(Fixed const & rhs);

	private:
		int	_rawBits;
		
		static const int _prec;
};

#endif

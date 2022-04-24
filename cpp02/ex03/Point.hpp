#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		Point	& operator=(Point const & rhs);
		Point(Point const & src);
		Point(float const x, float const y);
		Point(void);
		~Point(void);

	private:

		Fixed const _x;
		Fixed const _y;
		// ...
	
};

std::ostream	& operator<<(std::ostream & o, Point const & p);

#endif

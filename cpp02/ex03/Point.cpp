#include "Point.hpp"

Fixed	Point::getX(void) const
{
	return this->_x;
}

Fixed	Point::getY(void) const
{
	return this->_y;
}

std::ostream	& operator<<(std::ostream & o, Point const & p)
{
	o << "(" << p.getX() << "," << p.getY() << ")";
	return o;
}

Point	& Point::operator=(Point const & rhs)
{
	(void) rhs;

	// *this = rhs;

	// this->_x = rhs.getX();
	// this->_y = rhs.getY();

	return *this;
}

Point::Point(Point const & src)
{
	*this = src;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(void) : _x(0), _y(0)
{
}

Point::~Point()
{
}

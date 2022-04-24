#include "Point.hpp"

const int Point::xMax = 10;
const int Point::yMax = 10;


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
	o << "(" << p.getX() << " ; " << p.getY() << ")";
	return o;
}

Point	& Point::operator=(Point const & rhs)
{
	(void) rhs;
	return *this;
}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
	// std::cout << "CONSTR COPY"<<std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "CONSTR DEFAUT"<<std::endl;
}

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "CONSTR DEFAULT"<<std::endl;
}

Point::~Point()
{
}

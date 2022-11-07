#include "Num.hpp"

Num::Num() : _x(0){}
Num::Num(int x) : _x(x){}
Num::~Num(){}
int Num::operator*() const {return _x;}
int Num::operator+(int rhs) const {return _x + rhs;}
int Num::getX() const {return _x;}

std::ostream	& operator<<(std::ostream & o, Num const & x)
{
	o << x.getX();
	return o;
}
#ifndef NUM_HPP
# define NUM_HPP

#include <iostream>

class Num
{
	public:
		Num();
		Num(int x);
		~Num();
		int operator*() const;
		int operator+(int rhs) const;
		int getX() const;
	private:
		int _x;
};

std::ostream & operator<<(std::ostream & o, Num const & x);

#endif
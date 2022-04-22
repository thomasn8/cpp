#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;					// Default
	Fixed const b( 10 );		// Int
	Fixed const c( 42.42f );	// Float
	Fixed const d( b );			// Copy + Assignement
	a = Fixed( 1234.4321f );	// Float + Assignement + Destructor

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "b_prt = " << &b << " | d_ptr = " << &d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

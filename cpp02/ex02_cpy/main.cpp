#include "Fixed.hpp"

/*
a is 1234.43
b is 10						// prob
c is 42.4219
d is 10						// prob
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
*/

// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;

// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	return 0;
// }


/* 
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/
 
int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;		// 0
	std::cout << ++a << std::endl;		// 0.00390625
	std::cout << a << std::endl;		// 0.00390625
	std::cout << a++ << std::endl;		// 0.00390625
	std::cout << a << std::endl;		// 0.0078125
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
} 

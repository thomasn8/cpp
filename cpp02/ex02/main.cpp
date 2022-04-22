#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;


	// std::cout << c << std::endl;
	// std::cout << c << std::endl;
	// Fixed c;
	// std::cout << c.getFixed() << " / " << c.getFloat() << std::endl;
	// ++c;
	// std::cout << c.getFixed() << " / " << c.getFloat() << std::endl;
	// float d;
	// d = 0.00390625;
	// d++;
	// std::cout << "d = " << d << std::endl;
	// d++;
	// std::cout << "d = " << d << std::endl;
}


/* 		// a(0)	
		// a		0				// 
		// ++a		0.00390625		// 
		// a		0.00390625		//
		//			0.00390625		// a++
		// a		0.0078125		//
		// b		10.1016			//
		//			// 10.1016		//
 */
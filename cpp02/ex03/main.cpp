#include "Point.hpp"
#include "bsp.h"

int main( void ) 
{
	// TRIANGLE
	Point const a(2.55f, 2.12f);
	Point const b(3.63f, 5.47f);
	Point const c(5.51f, 0.82f);

	// POINTS ISOLÉS
	Point const p1(5.97f, 3.78f);			// hors du triangle
	Point const p2(3.81f, 2.92f);			// dans le triangle
	Point const p3(3.81f, 1.57f);			// sur un côté du triangle
	Point const p4(5.51f, 0.82f);			// sur un angle du triangle
	Point const p5(5.00f, 1.50f);			// dans le triangle
	Point const p6(2.77f, 7.26f);			// hors du triangle
	
	// BSP DES POINTS ISOLÉS PAR RAPPORT AU TRIANGLE
	std::cout << std::endl;
	std::cout << "P1 :" << std::endl;
	bsp(a, b, c, p1);
	std::cout << std::endl;
	std::cout << "P2 :" << std::endl;
	bsp(a, b, c, p2);
	std::cout << std::endl;
	std::cout << "P3 :" << std::endl;
	bsp(a, b, c, p3);
	std::cout << std::endl;
	std::cout << "P4 :" << std::endl;
	bsp(a, b, c, p4);
	std::cout << std::endl;
	std::cout << "P5 :" << std::endl;
	bsp(a, b, c, p5);
	std::cout << std::endl;
	std::cout << "P6 :" << std::endl;
	bsp(a, b, c, p6);

	return 0;
}

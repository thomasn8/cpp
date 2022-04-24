#include "Point.hpp"
#include "bsp.h"
/* 
	Définition des bornes du plan 2D grâce à :
	static const int xMax = 10;
	static const int yMax = 10;
*/

// void	test(Point const a)
// {
// 	std::cout << "3: "<< a.getX() <<"		"<< &a <<"	"<< a << std::endl;
// }

int main( void ) 
{
	Point const a(2.55f, 2.12f);
	Point const b(3.63f, 5.47f);
	Point const c(5.51f, 0.82f);

	// Point const z(a);
	// Point const y = a;
	// std::cout << "z: " << z << std::endl;
	// std::cout << "y: " << y << std::endl;

	// Point const &aRef = a;
	// Point const &bRef = b;
	// Point const &cRef = c;

	// std::cout << "triangle-a: " << a << std::endl;
	// std::cout << "triangle-b: " << b << std::endl;
	// std::cout << "triangle-c: " << c << std::endl;

	Point const p1(5.97f, 3.78f);
	Point const p2(3.81f, 2.92f);
	// Point p3(f, f);

	// std::cout << "1: " << a.getX() <<"	" << &a <<"	"<< a << std::endl;

	bsp(&a, &b, &c, &p2);
	bsp(&a, &b, &c, &p1);
	// test(aRef);

	return 0;
}

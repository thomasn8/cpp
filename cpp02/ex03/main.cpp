#include "Point.hpp"

/* 
	Définition des bornes du plan 2D grâce à :
	static const int xMax = 10;
	static const int yMax = 10;
*/

int main( void ) 
{
	Point a(2.55f, 2.12f);
	Point b(3.63f, 5.47f);
	Point c(5.51f, 0.82f);

	std::cout << "triangle-a: " << a << std::endl;
	std::cout << "triangle-b: " << b << std::endl;
	std::cout << "triangle-c: " << c << std::endl;

	Point p1(5.97f, 3.78f);
	Point p2(3.81f, 2.92f);
	// Point p3(f, f);

	return 0;
}

#include "Point.hpp"
#include "bsp.h"
/* 
	Définition des bornes du plan 2D grâce à :
	static const int xMax = 10;
	static const int yMax = 10;
*/

int main( void ) 
{
	Point const a(2.55f, 2.12f);
	Point const b(3.63f, 5.47f);
	Point const c(5.51f, 0.82f);
	Point const p1(5.97f, 3.78f);
	Point const p2(3.81f, 2.92f);
	bsp(a, b, c, p2);
	bsp(a, b, c, p1);
	return 0;
}

#include "Point.hpp"


/* 
	BSP signifie Binary Space Partitioning

	a, b, c : Les sommets de notre cher triangle.

	point : Le point à évaluer.

	Retourne : True si le point est à l’intérieur du triangle. 
	False dans le cas contraire.
	Si le point est un sommet ou placé sur une arrête, la fonction retournera False. 
*/

// http://maxence.delannoy.pagesperso-orange.fr/pt_poly.htm

bool	castRayS(Point const a, Point const b, Point const c, Point const point)
{
	int crossing = 0;

	// point <-> a-b
		// step 1 (si ok -> step 2)
		// step 2 (si croisement -> crossing++)

	// point <-> a-c
		// step 1 (si ok -> step 2)
		// step 2 (si croisement -> crossing++)

	// SI CROSSING > 1 return false

	// point <-> b-c
		// step 1 (si ok -> step 2)
		// step 2 (si croisement -> crossing++)

	// SI CROSSING != 1 return false, sinon return true
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (castRayS(a, b, c, point) == false)
		return false;
	// if (castRayN(a, b, c, point) == false)
	// 	return false;
	// if (castRayW(a, b, c, point) == false)
	// 	return false;
	// if (castRayE(a, b, c, point) == false)
	// 	return false;
	return true;
}

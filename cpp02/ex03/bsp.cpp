#include "Point.hpp"

// calcule la coordonnée manquante lorsque qu'un vecteur croise un point
// et qu'on connait une des 2 coordonnées de ce point
Fixed	missingY(Point const *p1, Point const *p2, Fixed xV)
{
	float 	p1X = p1->getX().toFloat();
	float 	p1Y = p1->getY().toFloat();
	float 	p2X = p2->getX().toFloat();
	float 	p2Y = p2->getY().toFloat();
	float 	x = xV.toFloat();
	float 	y;
	float	m;
	float	b;

	m = (p2Y - p1Y) / (p2X - p1X);
	b = p1Y - m * p1X;
	y = m * x + b;
	std::cout << "cross in (" << x << " ; " << y << ")" << std::endl;
	return Fixed(y);
}

bool	castRayS(Point const *a, Point const *b, Point const *c, Point const *point)
{
	int		crossing = 0;
	Fixed	vY;				// coordonnée y sur le côté du triangle (vecteur)

	// std::cout << "CAST RAY SOUTH" << std::endl;

	if ( (point->getX() > a->getX() && point->getX() < b->getX()) ||
		 (point->getX() < a->getX() && point->getX() > b->getX()) )
	{
		std::cout << "A-B" << std::endl;
		vY = missingY(a, b, point->getX());
		if (vY < point->getY())
			crossing++;
	}
	if ( (point->getX() > a->getX() && point->getX() < c->getX()) ||
		 (point->getX() < a->getX() && point->getX() > c->getX()) )
	{
		std::cout << "A-C" << std::endl;
		vY = missingY(a, c, point->getX());
		if (vY < point->getY())
			crossing++;
	}
	if (crossing > 1)
		return false;
	if ( (point->getX() > b->getX() && point->getX() < c->getX()) ||
		 (point->getX() < b->getX() && point->getX() > c->getX()) )
	{
		std::cout << "B-C" << std::endl;
		vY = missingY(b, c, point->getX());
		if (vY < point->getY())
			crossing++;
	}
	std::cout << "Crossing after S ray = " << crossing << std::endl;
	if (crossing != 1)
		return false;
	return true;
}

bool bsp(Point const *a, Point const *b, Point const *c, Point const *point)
{
	// std::cout << "2: "<< a.getX() <<"		"<< &a <<"			"<< a << std::endl;

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

// void	castRayVertical(Point const *a, Point const *b, Point const *c, Point const *point, int *crossing)
// {
// 	Fixed	vY;	// coordonnée y sur le côté du triangle (vecteur)

// 	if ( (point->getX() > a->getX() && point->getX() < b->getX()) ||
// 		 (point->getX() < a->getX() && point->getX() > b->getX()) )
// 	{
// 		std::cout << "A-B" << std::endl;
// 		vY = missingY(a, b, point->getX());
// 		// if (vY < point->getY())
// 			(*crossing)++;
// 	}
// 	if ( (point->getX() > a->getX() && point->getX() < c->getX()) ||
// 		 (point->getX() < a->getX() && point->getX() > c->getX()) )
// 	{
// 		std::cout << "A-C" << std::endl;
// 		vY = missingY(a, c, point->getX());
// 		// if (vY < point->getY())
// 			(*crossing)++;
// 	}
// 	if ( (point->getX() > b->getX() && point->getX() < c->getX()) ||
// 		 (point->getX() < b->getX() && point->getX() > c->getX()) )
// 	{
// 		std::cout << "B-C" << std::endl;
// 		vY = missingY(b, c, point->getX());
// 		// if (vY < point->getY())
// 			(*crossing)++;
// 	}
// }

// bool bsp(Point const *a, Point const *b, Point const *c, Point const *point)
// {
// 	int	crossing = 0;

// 	castRayVertical(a, b, c, point, &crossing);
// 	std::cout << "Crossing after vertical ray = " << crossing << std::endl;
// 	// castRayN(a, b, c, point) == false);
// 	return true;
// }

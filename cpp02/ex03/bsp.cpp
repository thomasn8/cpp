#include "Point.hpp"

// calcule la coordonnée manquante lorsque qu'un vecteur croise un point
// et qu'on connait une des 2 coordonnées de ce point
Fixed	missingY(Point const p1, Point const p2, Fixed xV)
{
	float 	y;
	float	m;
	float	b;
	float 	p1X = p1.getX().toFloat();
	float 	p1Y = p1.getY().toFloat();
	float 	p2X = p2.getX().toFloat();
	float 	p2Y = p2.getY().toFloat();
	float 	x = xV.toFloat();

	m = (p2Y - p1Y) / (p2X - p1X);
	b = p1Y - m * p1X;
	y = m * x + b;

	return Fixed(y);
}

bool	castRayS(Point const a, Point const b, Point const c, Point const point)
{
	int		crossing = 0;
	Fixed	vY;				// coordonnée y sur le côté du triangle (vecteur)

	std::cout << "S-ray:" << std::endl;
	if ( (point.getX() > a.getX() && point.getX() < b.getX()) ||
		 (point.getX() < a.getX() && point.getX() > b.getX()) )
	{
		vY = missingY(a, b, point.getX());
		if (vY < point.getY())
			crossing++;
		if (vY < point.getY())
			std::cout << "A-B cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
	}
	if ( (point.getX() > a.getX() && point.getX() < c.getX()) ||
		 (point.getX() < a.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(a, c, point.getX());
		if (vY < point.getY())
			crossing++;
		if (vY < point.getY())
			std::cout << "A-C cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;		
	}
	// if (crossing > 1)
	// 	return false;
	if ( (point.getX() > b.getX() && point.getX() < c.getX()) ||
		 (point.getX() < b.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(b, c, point.getX());
		if (vY < point.getY())
			crossing++;
		if (vY < point.getY())
			std::cout << "B-C cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
	}
	if (crossing != 1)
	{
		std::cout << "Point outside of triangle" <<std::endl;
		return false;
	}
	return true;
}

bool	castRayN(Point const a, Point const b, Point const c, Point const point)
{
	int		crossing = 0;
	Fixed	vY;				// coordonnée y sur le côté du triangle (vecteur)

	std::cout << "N-ray:" << std::endl;
	if ( (point.getX() > a.getX() && point.getX() < b.getX()) ||
		 (point.getX() < a.getX() && point.getX() > b.getX()) )
	{
		vY = missingY(a, b, point.getX());
		if (vY > point.getY() && vY < Point::yMax)
			crossing++;
		if (vY > point.getY() && vY < Point::yMax)
			std::cout << "A-B cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
	}
	if ( (point.getX() > a.getX() && point.getX() < c.getX()) ||
		 (point.getX() < a.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(a, c, point.getX());
		if (vY > point.getY() && vY < Point::yMax)
			crossing++;
		if (vY > point.getY() && vY < Point::yMax)
			std::cout << "A-C cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
	}
	// if (crossing > 1)
	// 	return false;
	if ( (point.getX() > b.getX() && point.getX() < c.getX()) ||
		 (point.getX() < b.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(b, c, point.getX());
		if (vY > point.getY() && vY < Point::yMax)
			crossing++;
		if (vY > point.getY() && vY < Point::yMax)
			std::cout << "B-C cross in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
	}
	if (crossing != 1)
	{
		std::cout << "Point outside of triangle" <<std::endl;
		return false;
	}
	return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (castRayS(a, b, c, point) == false)
		return false;
	if (castRayN(a, b, c, point) == false)
		return false;
	// if (castRayW(a, b, c, point) == false)
	// 	return false;
	// if (castRayE(a, b, c, point) == false)
	// 	return false;
	return true;
}

// void	castRayVertical(Point const *a, Point const *b, Point const *c, Point const *point, int *crossing)
// {
// 	Fixed	vY;	// coordonnée y sur le côté du triangle (vecteur)

// 	if ( (point.getX() > a.getX() && point.getX() < b.getX()) ||
// 		 (point.getX() < a.getX() && point.getX() > b.getX()) )
// 	{
// 		std::cout << "A-B" << std::endl;
// 		vY = missingY(a, b, point.getX());
// 		// if (vY < point.getY())
// 			(*crossing)++;
// 	}
// 	if ( (point.getX() > a.getX() && point.getX() < c.getX()) ||
// 		 (point.getX() < a.getX() && point.getX() > c.getX()) )
// 	{
// 		std::cout << "A-C" << std::endl;
// 		vY = missingY(a, c, point.getX());
// 		// if (vY < point.getY())
// 			(*crossing)++;
// 	}
// 	if ( (point.getX() > b.getX() && point.getX() < c.getX()) ||
// 		 (point.getX() < b.getX() && point.getX() > c.getX()) )
// 	{
// 		std::cout << "B-C" << std::endl;
// 		vY = missingY(b, c, point.getX());
// 		// if (vY < point.getY())
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

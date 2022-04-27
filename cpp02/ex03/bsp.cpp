#include "Point.hpp"

/* ******************************************************* */
/* ******************** VERTICAL RAYS ******************** */

// calcule la coordonnée manquante du point lorsque que le rayon croise un côté
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

bool	verticalRay(Point const a, Point const b, Point const c, Point const point, char dir)
{
	int		crossing = 0;
	Fixed	vY;

	if ( (point.getX() > a.getX() && point.getX() < b.getX()) ||
		 (point.getX() < a.getX() && point.getX() > b.getX()) )
	{
		vY = missingY(a, b, point.getX());
		if ((dir == 'S' && vY < point.getY()) || (dir == 'N' && vY > point.getY()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
		}
	}
	if ( (point.getX() > a.getX() && point.getX() < c.getX()) ||
		 (point.getX() < a.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(a, c, point.getX());
		if ((dir == 'S' && vY < point.getY()) || (dir == 'N' && vY > point.getY()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
		}
	}
	if ( (point.getX() > b.getX() && point.getX() < c.getX()) ||
		 (point.getX() < b.getX() && point.getX() > c.getX()) )
	{
		vY = missingY(b, c, point.getX());
		if ((dir == 'S' && vY < point.getY()) || (dir == 'N' && vY > point.getY()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
		}
	}
	if (crossing != 1)
	{
		std::cout << "FALSE -> point outside of triangle" <<std::endl;
		return false;
	}
	return true;
}

/* ********************************************************* */
/* ******************** HORIZONTAL RAYS ******************** */

// calcule la coordonnée manquante du point lorsque que le rayon croise un côté
Fixed	missingX(Point const p1, Point const p2, Fixed yV)
{
	float 	x;
	float	m;
	float	b;
	float 	p1X = p1.getX().toFloat();
	float 	p1Y = p1.getY().toFloat();
	float 	p2X = p2.getX().toFloat();
	float 	p2Y = p2.getY().toFloat();
	float 	y = yV.toFloat();

	m = (p2Y - p1Y) / (p2X - p1X);
	b = p1Y - m * p1X;
	x = (y - b) / m;

	return Fixed(x);
}

bool	horizontalRay(Point const a, Point const b, Point const c, Point const point, char dir)
{
	int		crossing = 0;
	Fixed	vX;

	if ( (point.getY() > a.getY() && point.getY() < b.getY()) ||
		 (point.getY() < a.getY() && point.getY() > b.getY()) )
	{
		vX = missingX(a, b, point.getY());
		if ((dir == 'W' && vX < point.getX()) || (dir == 'E' && vX > point.getX()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << vX.toFloat() << " ; " << point.getY().toFloat() << ")" << std::endl;
		}
	}
	if ( (point.getY() > a.getY() && point.getY() < c.getY()) ||
		 (point.getY() < a.getY() && point.getY() > c.getY()) )
	{
		vX = missingX(a, c, point.getY());
		if ((dir == 'W' && vX < point.getX()) || (dir == 'E' && vX > point.getX()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << vX.toFloat() << " ; " << point.getY().toFloat() << ")" << std::endl;
		}
	}
	if ( (point.getY() > b.getY() && point.getY() < c.getY()) ||
		 (point.getY() < b.getY() && point.getY() > c.getY()) )
	{
		vX = missingX(b, c, point.getY());
		if ((dir == 'W' && vX < point.getX()) || (dir == 'E' && vX > point.getX()))
		{
			crossing++;
			std::cout << "RAY-" << dir << ": a-b crossed in (" << vX.toFloat() << " ; " << point.getY().toFloat() << ")" << std::endl;
		}
	}
	if (crossing != 1)
	{
		std::cout << "FALSE -> point outside of triangle" <<std::endl;
		return false;
	}
	return true;
}

/* ********************************************************* */
/* **************** CAST 4 RAYS: S, N, W, E **************** */

// dès qu'un rayon croise 0 ou plus qu'1 côté 	->		false
// si chaque rayon croise 1 seul côté 			->		true
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (verticalRay(a, b, c, point, 'S') == false)
		return false;
	if (verticalRay(a, b, c, point, 'N') == false)
		return false;
	if (horizontalRay(a, b, c, point, 'W') == false)
		return false;
	if (horizontalRay(a, b, c, point, 'E') == false)
		return false;
	std::cout << "TRUE -> point inside of triangle" <<std::endl;
	return true;
}

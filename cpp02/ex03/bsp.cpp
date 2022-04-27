#include "Point.hpp"
#include <stdio.h>

char	ft_putchar(int num)
{
	return (num + '0' + 49);
}

bool	crossing_check(int crossing)
{
	if (crossing != 1)
	{
		std::cout << "FALSE -> point outside of triangle" <<std::endl;
		return false;
	}
	return true;
}

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

// rayons S et N pour détecter des intersections avec les côtés du triangle
bool	verticalRay(Point const a, Point const b, Point const c, Point const point, char dir)
{
	Point	triangle[3] = {a, b, c};
	int		i = 0;
	int		j = 1;
	int		crossing = 0;
	Fixed	vY;

	for (int s = 0; s < 3; s++)
	{
		if ( (point.getX() > triangle[i].getX() && point.getX() < triangle[i + j].getX()) ||
			 (point.getX() < triangle[i].getX() && point.getX() > triangle[i + j].getX()) )
		{
			vY = missingY(triangle[i], triangle[i + j], point.getX());
			if ((dir == 'S' && vY < point.getY()) || (dir == 'N' && vY > point.getY()))
			{
				crossing++;
				std::cout << "RAY-" << dir << ": " <<  ft_putchar(i) << "-" << ft_putchar(i+j) << " crossed in (";
				std::cout << point.getX().toFloat() << " ; " << vY.toFloat() << ")" << std::endl;
			}
		}
		if (s != 0)
			i++;
		if (i != 1)
			j++;
		else
			j--;
	}
	return crossing_check(crossing);
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

// rayons W et E pour détecter des intersections avec les côtés du triangle
bool	horizontalRay(Point const a, Point const b, Point const c, Point const point, char dir)
{
	Point	triangle[3] = {a, b, c};
	int		i = 0;
	int		j = 1;
	int		crossing = 0;
	Fixed	vX;


	for (int s = 0; s < 3; s++)
	{		
		if ( (point.getY() > triangle[i].getY() && point.getY() < triangle[i + j].getY()) ||
			 (point.getY() < triangle[i].getY() && point.getY() > triangle[i + j].getY()) )
		{
			vX = missingX(triangle[i], triangle[i + j], point.getY());
			if ((dir == 'W' && vX < point.getX()) || (dir == 'E' && vX > point.getX()))
			{
				crossing++;
				std::cout << "RAY-" << dir << ": " <<  ft_putchar(i) << "-" << ft_putchar(i+j) << " crossed in (";
				std::cout << vX.toFloat() << " ; " << point.getY().toFloat() << ")" << std::endl;
			}
		}
		if (s != 0)
			i++;
		if (i != 1)
			j++;
		else
			j--;
	}
	return crossing_check(crossing);
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

#include <cmath>
#include "Point.hpp"

float	area( Point const p1, Point const p2, Point const p3 ) {
	return abs((p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY()))/2.0);
}

bool	isOnEdge( Point const p, Point const a, Point const b ) {
	float	abX = b.getX() - a.getX();
	float	abY = b.getY() - a.getY();
	float	apX = p.getX() - a.getX();
	float	apY = p.getY() - a.getY();
	float	crossProduct = abX * apY + abY * apX;
	float	dotProduct = abX * apX + abY * apY;
	float	lengthSquared = abX * abX + abY * abY;
	return (crossProduct == 0) && (dotProduct >= 0) && (dotProduct <= lengthSquared);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	if (point == a || point == b || point == c)
		return false;
	if (isOnEdge(point, a, b) || isOnEdge(point, b, c) || isOnEdge(point, c, a)) {
		return false;
	}
	float	A = area(a, b, c);
	float	A1 = area(point, b, c);
	float	A2 = area(a, point, c);
	float	A3 = area(a, b, point);
	return A == A1 + A2 + A3;
}

#include "Plane.h"

Plane::Plane(Point point, Vector normal) : point(point), normal(normal)
{
	d = -((normal.x * point.x) + (normal.y * point.y) + (normal.z * point.z));
}

float Plane::distance(Point p)
{
	Vector w = p - point;
	return this->normal.proj(w).magnitude();
}
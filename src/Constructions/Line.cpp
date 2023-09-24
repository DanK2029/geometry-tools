#include "Line.h"

Line::Line(Point point, Vector direction) : point(point), direction(direction) {}

Point Line::getPoint(float t)
{
	return point + (direction * t);
}
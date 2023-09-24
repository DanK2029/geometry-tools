#include "LineSegment.h"

LineSegment::LineSegment(Point start, Point end) : start(start), end(end)
{
	Vector vec = Vector(start, end);
	length = vec.magnitude();
	direction = vec.normalize();
}

Point LineSegment::getPoint(float t)
{
	float s = t / length;
	return start + (direction * s);
}
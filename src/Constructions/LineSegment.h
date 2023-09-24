#include "Point.h"
#include "Vector.h"

class LineSegment
{
public:
	Point start, end;
	Vector direction;
	float length;
	LineSegment(Point start, Point end);
	Point getPoint(float t);
};
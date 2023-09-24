#include "Point.h"
#include "Vector.h"

class Line
{
public:
	Point point;
	Vector direction;

	Line(Point point, Vector direction);
	Point getPoint(float t);
};
#include "Point.h"
#include "Vector.h"

class Plane
{
public:
	Point point;
	Vector normal;
	float d;

	Plane(Point point, Vector normal);
	float distance(Point point);
};
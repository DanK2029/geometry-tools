#include "Point.h"
#include "Vector.h"

Point::Point(float x, float y, float z) : x(x), y(y), z(z) {}

Point Point::operator+(const Point &p)
{
	return Point(x + p.x, y + p.y, z + p.z);
}

Point Point::operator+(const Vector &v)
{
	return Point(x + v.x, y + v.y, z + v.z);
}

Point Point::operator+(const float &s)
{
	return Point(x + s, y + s, z + s);
}

Vector Point::operator-(const Point &p)
{
	return Vector(x - p.x, y - p.y, z - p.z);
}

Point Point::operator-(const float &s)
{
	return Point(x - s, y - s, z - s);
}

Point Point::operator/(const float &s)
{
	return Point(x / s, y / s, z / s);
}

Point Point::operator*(const float &s)
{
	return Point(x * s, y * s, z * s);
}

bool Point::operator==(const Point &p) const
{
	return x == p.x && y == p.y && z == p.z;
}

std::ostream &operator<<(std::ostream &os, Point const &p)
{
	os << "{" << p.x << ", " << p.y << ", " << p.z << "}";
	return os;
}

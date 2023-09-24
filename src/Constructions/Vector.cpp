#include "Vector.h"
#include "Point.h"

#include <cmath>

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector::Vector(Point start, Point end)
{
	x = end.x - start.x;
	y = end.y - start.y;
	z = end.z - start.z;
}

Vector Vector::operator+(const Vector &v)
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator+(const float &s)
{
	return Vector(x + s, y + s, z + s);
}

Vector Vector::operator-(const Vector &v)
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator-(const float &s)
{
	return Vector(x - s, y - s, z - s);
}

Vector Vector::operator/(const float &s)
{
	return Vector(x / s, y / s, z / s);
}

Vector Vector::operator*(const float &s)
{
	return Vector(x * s, y * s, z * s);
}

bool Vector::operator==(const Vector &v) const
{
	return x == v.x && y == v.y && z == v.z;
}

float Vector::magnitude()
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

Vector Vector::normalize()
{
	float d = magnitude();
	return Vector(x, y, z) / d;
}

float Vector::dot(Vector &v)
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector Vector::cross(Vector &v)
{
	float x = y * v.z - z * v.y;
	float y = z * v.x - x * v.z;
	float z = x * v.y - y * v.x;
	return Vector(x, y, z);
}

Vector Vector::proj(Vector &v)
{
	return v * (this->dot(v) / powf(this->magnitude(), 2));
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
	os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
	return os;
}
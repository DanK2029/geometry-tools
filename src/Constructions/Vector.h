#include <iostream>

class Point;

class Vector
{
public:
	float x, y, z;

	Vector(float x = 0, float y = 0, float z = 0);
	Vector(Point start, Point end);

	Vector operator+(const Vector &v);
	Vector operator+(const float &s);
	Vector operator-(const Vector &v);
	Vector operator-(const float &s);
	Vector operator/(const float &s);
	Vector operator*(const float &s);
	bool operator==(const Vector &v) const;

	float magnitude();
	Vector normalize();
	float dot(Vector &v);
	Vector cross(Vector &v);
	Vector proj(Vector &v);

	friend std::ostream &operator<<(std::ostream &os, Vector const &v);
};
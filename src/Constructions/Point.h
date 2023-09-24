#include <iostream>

class Vector;

class Point
{
public:
	float x, y, z;

	Point(float x = 0, float y = 0, float z = 0);
	Point operator+(const Point &p);
	Point operator+(const Vector &v);
	Point operator+(const float &s);
	Vector operator-(const Point &p);
	Point operator-(const float &s);
	Point operator/(const float &s);
	Point operator*(const float &s);
	bool operator==(const Point &p) const;
	friend std::ostream &operator<<(std::ostream &os, Point const &p);
};
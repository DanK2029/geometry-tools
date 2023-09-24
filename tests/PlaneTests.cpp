#include <gtest/gtest.h>
#include "Constructions/Plane.h"

TEST(PlaneTests, Initialization)
{
	Plane plane(Point(1, 2, 3), Vector(0, 1, 0));
}

TEST(PlaneTests, PointToPlaneDistance)
{
	Point point(0, 1, 0);
	Plane plane(Point(), Vector(0, 1, 0));
	float distance = plane.distance(point);
	ASSERT_EQ(1, distance);
}
#include <gtest/gtest.h>
#include "Constructions/Point.h"
#include "Constructions/Vector.h"

TEST(PointTests, Initialization)
{
	Point p1;
	ASSERT_EQ(Point(0, 0, 0), p1);

	Point p2(1);
	ASSERT_EQ(Point(1, 0, 0), p2);

	Point p3(1, 2);
	ASSERT_EQ(Point(1, 2, 0), p3);

	Point p4(1, 2, 3);
	ASSERT_EQ(Point(1, 2, 3), p4);
}

TEST(PointTests, Add)
{
	Point p1(1, 2, 3);
	Point p2(4, 5, 6);
	Point sum = p1 + p2;
	ASSERT_EQ(Point(5, 7, 9), sum);

	Point scalarSum = p1 + 1;
	ASSERT_EQ(Point(2, 3, 4), scalarSum);

	Vector v(1, 2, 3);
	Point vectorPointSum = p1 + v;
	ASSERT_EQ(Point(2, 4, 6), vectorPointSum);
}

TEST(PointTests, Subtract)
{
	Point p1(9, 6, 3);
	Point p2(1, 2, 3);
	Vector difference = p1 - p2;
	ASSERT_EQ(Vector(8, 4, 0), difference);

	Point scalarDifference = p1 - 1;
	ASSERT_EQ(Point(8, 5, 2), scalarDifference);
}

TEST(PointTests, Multiply)
{
	Point p1(2, 3, 4);
	Point scalarProduct = p1 * 2;
	ASSERT_EQ(Point(4, 6, 8), scalarProduct);
}

TEST(PointTests, Divide)
{
	Point p1(2, 4, 6);
	Point scalarQuotient = p1 / 2;
	ASSERT_EQ(Point(1, 2, 3), scalarQuotient);
}

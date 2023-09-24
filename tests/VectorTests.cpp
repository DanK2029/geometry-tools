#include <gtest/gtest.h>
#include "Constructions/Vector.h"

#include <iostream>

TEST(VectorTests, Initialization)
{
	Vector v1;
	ASSERT_EQ(Vector(0, 0, 0), v1);

	Vector v2(1);
	ASSERT_EQ(Vector(1, 0, 0), v2);

	Vector v3(1, 2);
	ASSERT_EQ(Vector(1, 2, 0), v3);

	Vector v4(1, 2, 3);
	ASSERT_EQ(Vector(1, 2, 3), v4);
}

TEST(VectorTests, Add)
{
	Vector v1(1, 2, 3);
	Vector v2(4, 5, 6);
	Vector sum = v1 + v2;
	ASSERT_EQ(Vector(5, 7, 9), sum);

	Vector scalarSum = v1 + 1;
	ASSERT_EQ(Vector(2, 3, 4), scalarSum);
}

TEST(VectorTests, Subtract)
{
	Vector v1(9, 6, 3);
	Vector v2(1, 2, 3);
	Vector difference = v1 - v2;
	ASSERT_EQ(Vector(8, 4, 0), difference);

	Vector scalarDifference = v1 - 1;
	ASSERT_EQ(Vector(8, 5, 2), scalarDifference);
}

TEST(VectorTests, Multiply)
{
	Vector v1(2, 3, 4);
	Vector scalarProduct = v1 * 2;
	ASSERT_EQ(Vector(4, 6, 8), scalarProduct);
}

TEST(VectorTests, Divide)
{
	Vector v1(2, 4, 6);
	Vector scalarQuotient = v1 / 2;
	ASSERT_EQ(Vector(1, 2, 3), scalarQuotient);
}
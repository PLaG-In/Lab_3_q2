#include "stdafx.h"
#include "../Rectangle/Rectangle.h"

struct RectangleFixture
{
	CRectangle rect;
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture)

BOOST_AUTO_TEST_CASE(RectangleTrueInitiation)
{
	rect.SetWidth(6);
	rect.SetHeight(10);
	BOOST_CHECK(rect.GetWidth() == 6);
	BOOST_CHECK(rect.GetHeight() == 10);
	BOOST_CHECK(rect.GetArea() == 60);
	BOOST_CHECK(rect.GetPerimeter() == 32);
}

BOOST_AUTO_TEST_CASE(RectangleWithNegativeSides)
{
	rect.SetWidth(-1);
	rect.SetHeight(-1);
	BOOST_CHECK(rect.GetWidth() == 0);
	BOOST_CHECK(rect.GetHeight() == 0);
	BOOST_CHECK(rect.GetArea() == 0);
	BOOST_CHECK(rect.GetPerimeter() == 0);
}

BOOST_AUTO_TEST_CASE(RectangleHasPerimeter)
{
	rect.SetTop(1);
	rect.SetLeft(1);
	rect.SetRight(8);
	rect.SetBottom(4);
	BOOST_CHECK(rect.GetWidth() == 7);
	BOOST_CHECK(rect.GetHeight() == 3);
	BOOST_CHECK(rect.GetLeft() == 1);
	BOOST_CHECK(rect.GetTop() == 1);
	BOOST_CHECK(rect.GetRight() == 8);
	BOOST_CHECK(rect.GetBottom() == 4);
	BOOST_CHECK(rect.GetPerimeter() == 20);
	{
		rect.SetWidth(9);
		BOOST_CHECK(rect.GetPerimeter() == 24);
	}
	{
		rect.SetHeight(5);
		BOOST_CHECK(rect.GetPerimeter() == 28);
	}
}

BOOST_AUTO_TEST_CASE(RectangleHasArea)
{
	rect.SetLeft(2);
	rect.SetTop(2);
	rect.SetRight(4);
	rect.SetBottom(5);
	BOOST_CHECK(rect.GetWidth() == 2);
	BOOST_CHECK(rect.GetHeight() == 3);
	BOOST_CHECK(rect.GetLeft() == 2);
	BOOST_CHECK(rect.GetTop() == 2);
	BOOST_CHECK(rect.GetRight() == 4);
	BOOST_CHECK(rect.GetBottom() == 5);
	BOOST_CHECK(rect.GetArea() == 6);

	rect.SetWidth(7);
	BOOST_CHECK(rect.GetArea() == 21);

	rect.SetHeight(10);
	BOOST_CHECK(rect.GetArea() == 70);

}

BOOST_AUTO_TEST_CASE(RectangleMove)
{
	rect = CRectangle(1, 1, 3, 4);

	rect.Move(1, 1);
	BOOST_CHECK(rect.GetLeft() == 2);
	BOOST_CHECK(rect.GetTop() == 2);
	BOOST_CHECK(rect.GetRight() == 5);
	BOOST_CHECK(rect.GetBottom() == 6);

	rect.Move(-1, -1);
	BOOST_CHECK(rect.GetLeft() == 1);
	BOOST_CHECK(rect.GetTop() == 1);
	BOOST_CHECK(rect.GetRight() == 4);
	BOOST_CHECK(rect.GetBottom() == 5);

	rect.Move(2, -1);	
	BOOST_CHECK(rect.GetLeft() == 3);
	BOOST_CHECK(rect.GetTop() == 0);
	BOOST_CHECK(rect.GetRight() == 6);
	BOOST_CHECK(rect.GetBottom() == 4);
}

BOOST_AUTO_TEST_CASE(RectangleScale)
{
	rect = CRectangle(1, 1, 9, 4);

	rect.Scale(1, 1);
	BOOST_CHECK(rect.GetRight() == 10);
	BOOST_CHECK(rect.GetBottom() == 5);
	BOOST_CHECK(rect.GetWidth() == 9);
	BOOST_CHECK(rect.GetHeight() == 4);

	rect.Scale(2, 2);
	BOOST_CHECK(rect.GetRight() == 19);
	BOOST_CHECK(rect.GetBottom() == 9);
	BOOST_CHECK(rect.GetWidth() == 18);
	BOOST_CHECK(rect.GetHeight() == 8);

	rect.Scale(-2, -2);
	BOOST_CHECK(rect.GetRight() == 19);
	BOOST_CHECK(rect.GetBottom() == 9);
	BOOST_CHECK(rect.GetWidth() == 18);
	BOOST_CHECK(rect.GetHeight() == 8);

	rect.Scale(0, 0);
	BOOST_CHECK(rect.GetRight() == 1);
	BOOST_CHECK(rect.GetBottom() == 1);
	BOOST_CHECK(rect.GetWidth() == 0);
	BOOST_CHECK(rect.GetHeight() == 0);
}

BOOST_AUTO_TEST_CASE(RectanglWithNoIntersection)
{
	CRectangle rect1(1, 1, 8, 8);
	CRectangle rect2(10, 10, 1, 1);
	BOOST_CHECK(!rect1.Intersect(rect2));
	BOOST_CHECK_EQUAL(rect1.GetHeight(), 0);
	BOOST_CHECK_EQUAL(rect1.GetWidth(), 0);
}
BOOST_AUTO_TEST_CASE(RectanglIntersection1)
{
	CRectangle rect1 = CRectangle(1, 1, 2, 2);
	CRectangle rect2 = CRectangle(2, 0, 2, 2);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK(rect1.GetLeft() == 2);
	BOOST_CHECK(rect1.GetTop() == 1);
	BOOST_CHECK(rect1.GetRight() == 3);
	BOOST_CHECK(rect1.GetBottom() == 2);
}
BOOST_AUTO_TEST_CASE(RectanglIntersection2)
{
	CRectangle rect1(1, 1, 2, 2);
	CRectangle rect2(0, 2, 2, 2);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK(rect1.GetLeft() == 1);
	BOOST_CHECK(rect1.GetTop() == 2);
	BOOST_CHECK(rect1.GetRight() == 2);
	BOOST_CHECK(rect1.GetBottom() == 3);
}
BOOST_AUTO_TEST_CASE(RectanglIntersection3)
{
	CRectangle rect1(1, 1, 2, 2);
	CRectangle rect2(0, 0, 2, 2);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK(rect1.GetLeft() == 1);
	BOOST_CHECK(rect1.GetTop() == 1);
	BOOST_CHECK(rect1.GetRight() == 2);
	BOOST_CHECK(rect1.GetBottom() == 2);
}
BOOST_AUTO_TEST_CASE(RectanglIntersection4)
{
	CRectangle rect1(1, 1, 2, 2);
	CRectangle rect2(1, 1, 2, 2);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK(rect1.GetLeft() == 1);
	BOOST_CHECK(rect1.GetTop() == 1);
	BOOST_CHECK(rect1.GetRight() == 3);
	BOOST_CHECK(rect1.GetBottom() == 3);
}
BOOST_AUTO_TEST_CASE(RectanglIntersection5)
{
	CRectangle rect1(1, 1, 2, 2);
	CRectangle rect2(1, 1, 1, 1);
	BOOST_CHECK(rect1.Intersect(rect2));
	BOOST_CHECK(rect1.GetLeft() == 1);
	BOOST_CHECK(rect1.GetTop() == 1);
	BOOST_CHECK(rect1.GetRight() == 2);
	BOOST_CHECK(rect1.GetBottom() == 2);
}

BOOST_AUTO_TEST_SUITE_END()
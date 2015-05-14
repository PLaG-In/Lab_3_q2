#include "stdafx.h"
#include "../Rectangle/Rectangle.h"

struct RectangleFixture
{
	CRectangle rect;
};

bool RectanglesAreEqual(CRectangle const& rect1, CRectangle const& rect2)
{	
	if (rect1.GetLeft() == rect2.GetLeft()
		&& rect1.GetTop() == rect2.GetTop()
		&& rect1.GetWidth() == rect2.GetWidth()
		&& rect1.GetHeight() == rect2.GetHeight())
	{
		return true;
	}
	return false;
}
BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture)

BOOST_AUTO_TEST_CASE(RectangleDefineParameters)
{
	{
		CRectangle rect(18, 10, 94, 10);
		BOOST_CHECK_EQUAL(rect.GetLeft(), 18);
		BOOST_CHECK_EQUAL(rect.GetTop(), 10);
		BOOST_CHECK_EQUAL(rect.GetRight(), 112);
		BOOST_CHECK_EQUAL(rect.GetBottom(), 20);
		BOOST_CHECK_EQUAL(rect.GetWidth(), 94);
		BOOST_CHECK_EQUAL(rect.GetHeight(), 10);
	}
	{
		CRectangle rect(9, 5, -45, 6);
		BOOST_CHECK_EQUAL(rect.GetLeft(), 9);
		BOOST_CHECK_EQUAL(rect.GetTop(), 5);
		BOOST_CHECK_EQUAL(rect.GetRight(), 9);
		BOOST_CHECK_EQUAL(rect.GetBottom(), 11);
		BOOST_CHECK_EQUAL(rect.GetWidth(), 0);
		BOOST_CHECK_EQUAL(rect.GetHeight(), 6);
	}
	{
		CRectangle rect(26, 4, 86, -4);
		BOOST_CHECK_EQUAL(rect.GetLeft(), 26);
		BOOST_CHECK_EQUAL(rect.GetTop(), 4);
		BOOST_CHECK_EQUAL(rect.GetRight(), 112);
		BOOST_CHECK_EQUAL(rect.GetBottom(), 4);
		BOOST_CHECK_EQUAL(rect.GetWidth(), 86);
		BOOST_CHECK_EQUAL(rect.GetHeight(), 0);
	}
}

BOOST_AUTO_TEST_CASE(NegativeSizes)
{
	CRectangle rect(20, -5, -30, -10);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 0);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 0);

	rect.SetWidth(1);
	rect.SetHeight(1);

	rect.SetWidth(-5);
	BOOST_CHECK_EQUAL(rect.GetWidth(), 0);

	rect.SetHeight(-60);
	BOOST_CHECK_EQUAL(rect.GetHeight(), 0);
}

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
	rect = CRectangle(1, 1, 7, 3);;
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
	rect = CRectangle(2, 2, 3, 4);
	BOOST_CHECK(rect.GetArea() == 12);

	rect.SetWidth(7);
	BOOST_CHECK(rect.GetArea() == 28);

	rect.SetHeight(10);
	BOOST_CHECK(rect.GetArea() == 70);

}

BOOST_AUTO_TEST_CASE(RectangleMove)
{
	rect = CRectangle(1, 1, 3, 4);
	CRectangle testRect(2, 2, 4, 5);
	rect.Move(1, 1);
	RectanglesAreEqual(rect, testRect);

	rect.Move(-1, -1);
	testRect = CRectangle(1, 1, 3, 4);
	RectanglesAreEqual(rect, testRect);

	rect.Move(2, -1);
	testRect = CRectangle(3, 0, 5, 3);
	RectanglesAreEqual(rect, testRect);
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
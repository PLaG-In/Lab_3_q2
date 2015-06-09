#include "stdafx.h"
#include "../Rectangle/Canvas.h"

BOOST_AUTO_TEST_SUITE(Canvas)

BOOST_AUTO_TEST_CASE(CanCreateCanvas)
{
	CCanvas canvas(10, 10);
	BOOST_CHECK_EQUAL(canvas.GetHeight(), 10);
	BOOST_CHECK_EQUAL(canvas.GetWidth(), 10);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			BOOST_CHECK_EQUAL(canvas.GetPixel(i, j), ' ');
		}
	}
}

BOOST_AUTO_TEST_CASE(CanSetPixels)
{
	CCanvas canvas(10, 10);
	canvas.SetPixel(1, 1, '&');
	BOOST_CHECK_EQUAL(canvas.GetPixel(1, 1), '&');
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			canvas.SetPixel(i, j, '$');
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			BOOST_CHECK_EQUAL(canvas.GetPixel(i, j), '$');
		}
	}
}

BOOST_AUTO_TEST_CASE(CanClear)
{
	CCanvas canvas(10, 10);
	canvas.SetPixel(1, 1, '&');
	BOOST_CHECK_EQUAL(canvas.GetPixel(1, 1), '&');
	canvas.Clear();
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			BOOST_CHECK_EQUAL(canvas.GetPixel(i, j), ' ');
		}
	}
	canvas.Clear('^');
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			BOOST_CHECK_EQUAL(canvas.GetPixel(i, j), '^');
		}
	}
}

BOOST_AUTO_TEST_SUITE_END()
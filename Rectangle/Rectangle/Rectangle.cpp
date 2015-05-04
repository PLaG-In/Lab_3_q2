// Rectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Rectangle.h"

CRectangle::CRectangle()
	: m_height(0)
	, m_width(0)
	, m_left(0)
	, m_top(0)
{
}

CRectangle::CRectangle(int left, int top, int width, int height)
	: m_height(std::max(0, height))
	, m_width(std::max(0, width))
	, m_left(left)
	, m_top(top)
{
}

CRectangle::~CRectangle()
{
}

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

int CRectangle::GetBottom() const
{
	return m_top + m_height;
}

int CRectangle::GetTop() const
{
	return m_top;
}

int CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

void CRectangle::SetWidth(int width)
{
	m_width = width < 0 ? 0 : width;
}

void CRectangle::SetHeight(int height)
{
	m_height = height < 0 ? 0 : height;
}

void CRectangle::SetLeft(int x)
{
	m_left = x;
}

void CRectangle::SetRight(int right)
{
	m_width = right > m_left ? right - m_left : m_width;
}

void CRectangle::SetBottom(int bottom)
{
	m_height = bottom > m_top ? bottom - m_top : m_height;
}

void CRectangle::SetTop(int y)
{
	m_top = y;
}

void CRectangle::Move(int dx, int dy)
{
	SetLeft(m_left + dx);
	SetTop(m_top + dy);
}

void CRectangle::Scale(int sx, int sy)
{
	if (!(sx < 0 || sy < 0))
	{
		SetWidth(m_width * sx);
		SetHeight(m_height * sy);
	}
}

bool CRectangle::Intersect(const CRectangle &other)
{
	int lw = m_left + m_width, th = m_top + m_height;
	int lw1 = other.m_left + other.m_width
		, th1 = other.m_top + other.m_height;

	int minX = m_left < other.m_left ? other.m_left : m_left;
	int maxX = lw < lw1 ? lw : lw1;
	int minY = m_top < other.m_top ? other.m_top : m_top;
	int maxY = th < th1 ? th : th1;
	
	if (maxX > minX && maxY > minY)
	{
		m_left = minX;
		m_top = minY;
		m_width = maxX - minX;
		m_height = maxY - minY;
		return true;
	}

	m_width = 0;
	m_height = 0;
	return false;
}
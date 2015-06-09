#include "stdafx.h"
#include "Canvas.h"


CCanvas::CCanvas(unsigned width, unsigned height)
{
	m_width = width;
	m_height = height;

	m_canvas = new char*[width];
	for (unsigned i = 0; i < width; ++i)
	{
		m_canvas[i] = new char[height];
		memset(m_canvas[i], ' ', height * sizeof(char));
	}
}


unsigned CCanvas::GetWidth() const
{
	return m_width;
}

unsigned CCanvas::GetHeight() const
{
	return m_height;
}

char CCanvas::GetPixel(int x, int y) const
{
	return IsValidCoord(x, y) ? m_canvas[x][y] : ' ';
}

void CCanvas::Write(std::ostream &ostream) const
{
	for (unsigned i = 0; i < m_height; ++i)
	{
		for (unsigned j = 0; j < m_width; ++j)
		{
			ostream << m_canvas[j][i];
		}
		ostream << std::endl;
	}
}

void CCanvas::Clear(char code)
{
	if (code < ' ')
	{
		return;
	}
	for (unsigned i = 0; i < m_width; ++i)
	{
		memset(m_canvas[i], code, m_height * sizeof(char));
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (IsValidCoord(x, y) && code >= ' ')
	{
		m_canvas[x][y] = code;
	}
}

bool CCanvas::IsValidCoord(int x, int y) const
{
	return !(x < 0 || y < 0 || x >= m_width || y >= m_height);
}

CCanvas::~CCanvas()
{
	for (unsigned i = 0; i < m_width; ++i)
	{
		delete[] m_canvas[i];
		m_canvas[i] = nullptr;
	}
	delete[] m_canvas;
	m_canvas = nullptr;
}
#pragma once

class CRectangle
{
public:
	CRectangle();
	CRectangle(int left, int top, int width, int height);
	~CRectangle();

	int GetWidth() const;
	int GetHeight() const;
	int GetLeft() const;
	int GetRight() const;
	int GetBottom() const;
	int GetTop() const;
	
	int GetArea() const;
	int GetPerimeter() const;

	void SetWidth(int width);
	void SetHeight(int height);
	void SetRight(int right);
	void SetLeft(int xCoordinate);
	void SetBottom(int bottom);
	void SetTop(int yCoordinate);
	
	void Move(int dx, int dy);
	void Scale(int sx, int sy);

	bool Intersect(CRectangle const& other);
private:
	int m_width;
	int m_height;
	int m_left;
	int m_top;
};


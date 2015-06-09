#pragma once

class CCanvas
{
public:
	CCanvas(unsigned width, unsigned height);

	unsigned GetWidth() const;
	unsigned GetHeight() const;

	void Clear(char code = ' ');
	void SetPixel(int x, int y, char code);
	char GetPixel(int x, int y) const;
	void Write(std::ostream & ostream) const;
	~CCanvas();
private:
	bool IsValidCoord(int x, int y) const;
	char **m_canvas;
	unsigned m_width;
	unsigned m_height;
};
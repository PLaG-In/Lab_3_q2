#include "stdafx.h"
#include "Rectangle.h"
#include "Canvas.h"

using namespace std;

void RectangleActions(CRectangle &rect, ifstream &fin)
{
	string action;
	fin >> action;
	if (action == "Rectangle")
	{
		int width, height, left, top;
		fin >> left >> top >> width >> height;
		rect.SetLeft(left);
		rect.SetTop(top);
		rect.SetWidth(width);
		rect.SetHeight(height);
	}
	else if (action == "Move")
	{
		int dx, dy;
		fin >> dx >> dy;
		rect.Move(dx, dy);
	}
	else
	{
		if (action == "Scale")
		{
			int sx, sy;
			fin >> sx >> sy;
			rect.Scale(sx, sy);
		}
		else
		{
			cout << action << " : wrong command\n";
			return;
		}
	}
}

void PrintRectangleParameters(const CRectangle &rect)
{
	cout << "   Left Top: (" << rect.GetLeft() << "; " << rect.GetTop() << ")\n" ;
	cout << "   Size: " << rect.GetWidth() << "*" << rect.GetHeight() << endl;;
	cout << "   Right Bottom: (" << rect.GetRight() << "; " << rect.GetBottom() << ")\n";
	cout << "	Area: " << rect.GetArea() << endl;
	cout << "	Perimeter: " << rect.GetPerimeter() << endl;
}

bool ReadFileAndFillVector(const char *fileName, vector<CRectangle> &rectangles)
{
	ifstream fin(fileName);
	if (!fin)
	{
		return false;
	}
	CRectangle rect;
	string str;
	while (fin.good())
	{
		RectangleActions(rect, fin);
	}
	rectangles.push_back(rect);
	fin.close();
	return true;
}

void FillRectangle(const CRectangle &rect, char code, CCanvas &canvas)
{
	unsigned x = rect.GetLeft();
	unsigned y = rect.GetTop();
	for (size_t i = 0; i < rect.GetWidth(); ++i)
	{
		for (size_t j = 0; j < rect.GetHeight(); ++j)
		{
			canvas.SetPixel(i + x, j + y, code);
		}
	}
}

void PrintCanvasWithRect(const vector<CRectangle> &rectangles, CCanvas &canvas, std::ostream &ostream)
{
	FillRectangle(rectangles[0], '+', canvas);
	FillRectangle(rectangles[1], '-', canvas);
	FillRectangle(rectangles[2], '#', canvas);
	canvas.Write(ostream);
}



int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: lab3 [file1] [file2] \n";
	}
	vector<CRectangle> rectangles;
	if (!ReadFileAndFillVector(argv[1], rectangles))
	{
		cout << "File doesn't exist: " << argv[1] << endl;
		return 1;
	}

	if (!ReadFileAndFillVector(argv[2], rectangles))
	{
		cout << "File doesn't exist: " << argv[2] << endl;
		return 1;
	}

	for (size_t i = 0; i < 2; i++)
	{
		cout << "Rectangle " << i + 1 << ":\n";
		PrintRectangleParameters(rectangles[i]);
	}

	CRectangle intersectRect = rectangles[0];
	rectangles[2].Intersect(rectangles[1]);
	cout << "Intersection rectangle:\n";
	PrintRectangleParameters(rectangles[2]);
	CCanvas canvas(60, 20);
	if (argc > 3)
	{
		ofstream ofStrm(argv[3]);
		PrintCanvasWithRect(rectangles, canvas, ofStrm);
	}
	else
	{
		PrintCanvasWithRect(rectangles, canvas, cout);
	}

	return 0;
}

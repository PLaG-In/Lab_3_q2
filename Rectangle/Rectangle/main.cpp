// main.cpp : Defines the enttempRectry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"

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


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Usage: lab3 [file1] [file2] \n";
		return 1;
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

	for (size_t i = 0; i < rectangles.size(); i++)
	{
		cout << "Rectangle " << i + 1 << ":\n";
		PrintRectangleParameters(rectangles[i]);
	}

	CRectangle intersectRect = rectangles[0];
	intersectRect.Intersect(rectangles[1]);
	cout << "Intersection rectangle:\n";
	PrintRectangleParameters(intersectRect);
	system("pause");
	return 0;
}

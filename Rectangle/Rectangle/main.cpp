// main.cpp : Defines the enttempRectry point for the console application.
//

#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

void WorkWithRect(CRectangle &tempRect, const string &action, ifstream &fin)
{
	if (action == "Rectangle")
	{
		int width, height, left, top;
		fin >> left >> top >> width >> height;
		tempRect.SetLeft(left);
		tempRect.SetTop(top);
		tempRect.SetWidth(width);
		tempRect.SetHeight(height);
	}
	else if (action == "Move")
	{
		int dx, dy;
		fin >> dx >> dy;
		tempRect.Move(dx, dy);
	}
	else
	{
		if (action == "Scale")
		{
			int sx, sy;
			fin >> sx >> sy;
			tempRect.Scale(sx, sy);
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

bool ReadFile(const char *fileName, vector<CRectangle> &rectangles)
{
	ifstream fin(fileName);
	if (!fin)
	{
		return false;
	}
	CRectangle tempRect = CRectangle();
	string str;
	while (fin.good())
	{
		fin >> str;
		WorkWithRect(tempRect, str, fin);
	}
	rectangles.push_back(tempRect);
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
	if (!ReadFile(argv[1], rectangles))
	{
		cout << "File doesn't exist: " << argv[1] << endl;
		return 1;
	}

	if (!ReadFile(argv[2], rectangles))
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

#pragma once

#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")

using Gdiplus::Graphics;
using Gdiplus::Image;
using Gdiplus::Point;

#include <vector>
#include <list>
#include <map>

using std::vector;
using std::list;
using std::map;


class Coord{
public:
	Coord(int _X, int _Y, int _Z); 
		
	int X;
	int Y;
	int Z;
};
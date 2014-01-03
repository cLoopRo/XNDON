#pragma once

#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")

using Gdiplus::Graphics;
using Gdiplus::Image;
using Gdiplus::Point;
using Gdiplus::CachedBitmap;

#include <vector>
#include <list>
#include <map>
#include <queue>



using std::vector;
using std::list;
using std::map;
using std::queue;

#include <string>
using std::wstring;


class Vector3{
public:
	Vector3( ){	};
	Vector3(int _X, int _Y, int _Z) : X(_X), Y(_Y), Z(_Z)
	{	}; 
		
	int X;
	int Y;
	int Z;
};

static bool keys[256];	// Array Used For The Keyboard Routine

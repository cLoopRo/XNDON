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

#include <ctime>
//#include <tchar.h>

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


int const CL_WIN_WIDTH_PIXEL = 800; 
int const CL_WIN_HEIGHT_PIXEL = 640;

/*

PWSTR  lpszStr = L("My string"); // 유니코트 문자열로 지정하는 매크로 함수 L()
'W' => 유니코드

TCHAR : Windows시스템에서 유니코드와 MBCS(Multi Byte Character Set)을 지원하기 위해 TCHAR을 사용
TCHAR 을 나타는 매크로 _T : (한문자 _T(' '), 문장 _T(" "))

MultiByte 는 어떤 글씨는 1바이트 이고 어떤 글씨는 2바이트여서 메모리 관리가 어렵다.
그래서 나온 것이 wchar 인데, wchar 는 모든 글씨(영문 포함)가 2바이트로 구성이 된다.
당연히 wchar 는 일반 ascii 타입의 char 보다 메모리 공간이 2배 필요하다.

TCHAR 는 ACSCII 타입의 일반 char 또는 wchar 라는 의미다.
TCHAR 을 사용하면 char 인지 wchar 인지 구별하지 않고 그냥 코딩을 하면 된다.

CHAR * == LPSTR == PSTR
CONST CHAR * == LPCSTR == PCSTR

LPTSTR  = TCHAR *
LPCTSTR = CONST TCHAR *

'C' => const 의 의미, 'LP' => long pointer 의 의미.
'STR' => NULL 포인터로 끝난다의 의미


ANSI            Unicode          TCHAR type
--------------------------------------
strlen()        wcslen()         _tcslen()
strcat()        wcscat()         _tcscat()
strchr()        wcschr()         _tcschr()
strcmp()      wcscmp()       _tcscmp()
strcpy()       wcscpy()        _tcscpy()
strstr()         wcsstr()          _tcsstr()
strrev()        _wcsrev()        _tcsrev()

printf()         wprintf()           _tprintf()
sprintf()       swprintf()         _stprintf()
scanf()        wscanf()          _tscanf()
=> tchar.h 에 정의되어 있음 


BYTE	unsigned char형
WORD	unsigned short형
DWORD	unsigned long(int)형



*/


#pragma once

// Direct2D Header
#include <d2d1.h>

// �������ڸ� ����ϱ� ���� ���
#include <cstdarg>


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
using std::deque;

#include <tchar.h>
#include <string>
using std::wstring;

#include <ctime>
//#include <tchar.h>

template<class T>
class Vector3{
public:
	Vector3( ){	}
	Vector3(T _X, T _Y, T _Z) : X(_X), Y(_Y), Z(_Z)
	{	}
		
	T X;
	T Y;
	T Z;
};

static bool keys[256];	// Array Used For The Keyboard Routine


int const CL_WIN_WIDTH_PIXEL = 960; 
int const CL_WIN_HEIGHT_PIXEL = 540;

int const ANIMATION_FRAME = 4;
double const ANIMATION_PERIOD = 1.0/ANIMATION_FRAME;

/*

PWSTR  lpszStr = L("My string"); // ������Ʈ ���ڿ��� �����ϴ� ��ũ�� �Լ� L()
'W' => �����ڵ�

TCHAR : Windows�ý��ۿ��� �����ڵ�� MBCS(Multi Byte Character Set)�� �����ϱ� ���� TCHAR�� ���
TCHAR �� ��Ÿ�� ��ũ�� _T : (�ѹ��� _T(' '), ���� _T(" "))

MultiByte �� � �۾��� 1����Ʈ �̰� � �۾��� 2����Ʈ���� �޸� ������ ��ƴ�.
�׷��� ���� ���� wchar �ε�, wchar �� ��� �۾�(���� ����)�� 2����Ʈ�� ������ �ȴ�.
�翬�� wchar �� �Ϲ� ascii Ÿ���� char ���� �޸� ������ 2�� �ʿ��ϴ�.

TCHAR �� ACSCII Ÿ���� �Ϲ� char �Ǵ� wchar ��� �ǹ̴�.
TCHAR �� ����ϸ� char ���� wchar ���� �������� �ʰ� �׳� �ڵ��� �ϸ� �ȴ�.

CHAR * == LPSTR == PSTR
CONST CHAR * == LPCSTR == PCSTR

LPTSTR  = TCHAR *
LPCTSTR = CONST TCHAR *

'C' => const �� �ǹ�, 'LP' => long pointer �� �ǹ�.
'STR' => NULL �����ͷ� �������� �ǹ�


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
=> tchar.h �� ���ǵǾ� ���� 


BYTE	unsigned char��
WORD	unsigned short��
DWORD	unsigned long(int)��



*/

	
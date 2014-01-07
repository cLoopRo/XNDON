#pragma once

#include "main.h"
#include "XDScene.h"

class XDDirector
{
public:
	XDDirector(void);
	~XDDirector(void);

//	static inline HWND get_hWndMain(){	return _hWndMain;	}
//	static inline void set_hWndMain(HWND _HWndMain){	_hWndMain = _HWndMain;	}

private:
//	static HWND _hWndMain;
	static XDScene* _scene;


};


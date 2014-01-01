#include <windows.h>
 
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("GdiPlusStart");
 
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus")
 //nays850 git push test 2014.01.01/5:28 PM/
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
       ,LPSTR lpszCmdParam,int nCmdShow)
{
     HWND hWnd;
     MSG Message;
     WNDCLASS WndClass;
     g_hInst=hInstance;
 
     ULONG_PTR gpToken;
     GdiplusStartupInput gpsi;
     if (GdiplusStartup(&gpToken,&gpsi,NULL) != Ok) {
          MessageBox(NULL,TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."),
              TEXT("알림"),MB_OK);
          return 0;
     }
 
     WndClass.cbClsExtra=0;
     WndClass.cbWndExtra=0;
     WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
     WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
     WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
     WndClass.hInstance=hInstance;
     WndClass.lpfnWndProc=WndProc;
     WndClass.lpszClassName=lpszClass;
     WndClass.lpszMenuName=NULL;
     WndClass.style=CS_HREDRAW | CS_VREDRAW;
     RegisterClass(&WndClass);
 
     hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
          CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
          NULL,(HMENU)NULL,hInstance,NULL);
     ShowWindow(hWnd,nCmdShow);
 
     while (GetMessage(&Message,NULL,0,0)) {
          TranslateMessage(&Message);
          DispatchMessage(&Message);
     }
     GdiplusShutdown(gpToken);
     return (int)Message.wParam;
}
 
void OnPaint(HDC hdc)
{
     Graphics G(hdc);
     Pen P(Color(255,0,0,255),5);
 
     G.DrawEllipse(&P,10,10,300,200);
}
 
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
     HDC hdc;
     PAINTSTRUCT ps;
 
     switch (iMessage) {
     case WM_CREATE:
          hWndMain=hWnd;
          return 0;
     case WM_PAINT:
          hdc=BeginPaint(hWnd, &ps);
          OnPaint(hdc);
          EndPaint(hWnd, &ps);
          return 0;
     case WM_DESTROY:
          PostQuitMessage(0);
          return 0;
     }
     return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
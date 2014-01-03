#include "main.h"
#include "Render.h"
#include "ResManager.h"
//잠시 테스트합니다.
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("XNDON");

Scene* Render :: pScene = NULL;
vector<Sprite> Render :: sceneObject;
std::map<WCHAR*, Image* > ResManager :: image_Map;



 //nays850 git push test 2014.01.01/5:28 PM/
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
       ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst=hInstance;
	
	/*<----- GdiPlus 시작 ----->*/
	ULONG_PTR gpToken;
    Gdiplus::GdiplusStartupInput gpsi;
    if ( Gdiplus::GdiplusStartup(&gpToken,&gpsi,NULL) != Gdiplus::Ok) {
		MessageBox(NULL,TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."),
		TEXT("알림"),MB_OK);
		return 0;
	} 
	/*<------------------------>*/
 
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
		0 , 0, 1280, 720, NULL,(HMENU)NULL,hInstance,NULL);
	
	ShowWindow(hWnd,nCmdShow);
 
    while ( GetMessage(&Message,NULL,0,0) )
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
    }

	/*<----- GDI+ 종료 ----->*/
	Gdiplus::GdiplusShutdown(gpToken);
	/*<--------------------->*/

	return (int)Message.wParam;
}
 
void OnPaint(HDC hdc)
{
     Graphics G(hdc);
     Gdiplus::Pen P( Gdiplus::Color(255,0,0,255),5);
 
     G.DrawEllipse(&P,10,10,300,200);
}


void CALLBACK update(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	HDC hdc = GetDC(hWnd);
	Graphics G(hdc);
	using namespace Gdiplus;

    SolidBrush RESET( Color(255,255,255,255) );
	G.FillRectangle(&RESET,0,0,1280,760);

	Font F(L"굴림",20,FontStyleRegular,UnitPixel);

//	TCHAR *Hangul=L"한글 문자열";
	TCHAR szWidth[128];
	RectF bound;
	SolidBrush B(Color(0,0,0));
//	G.DrawString(Hangul,-1,&F,PointF(0,00),&B);
//	G.MeasureString(Hangul,-1,&F,PointF(0,0),&bound);
	static unsigned int lastTime;
	swprintf(szWidth,TEXT("dwTime:%u, 프레임 : %.2lf"), dwTime, 1000.0/(dwTime-lastTime) );
	lastTime = dwTime;
	
	
	
	G.DrawString(szWidth,-1,&F, PointF(0,6),&B);

	ReleaseDC(hWnd, hdc);

	Render::draw(hdc);

	Render::sceneUpdate( );
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
     HDC hdc;
     PAINTSTRUCT ps;
	
	 static HANDLE hTimer;
     switch (iMessage) {
     case WM_CREATE:
          hWndMain = hWnd;
		 
		  // SetTimer() 으로 타이머 설치, KillTimer() 으로 타이머 해제
		  // 우선순위가 낮으므로 정확도를 위해서는 타이머 콜백 함수 사용 => 네번째 인자에 콜백함수 포함
		  hTimer= (HANDLE) SetTimer( hWnd, 1, 30, update );
          
		  
		  return 0;
	 case WM_TIMER:
		  InvalidateRect(hWnd, NULL, TRUE);
		  return 0;
     case WM_PAINT:

          hdc=BeginPaint(hWnd, &ps);
          Render::draw(hdc);
		  EndPaint(hWnd, &ps);
          
		  return 0;
     case WM_DESTROY:
          PostQuitMessage(0);
          return 0;
     }
     return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

#include "main.h"
#include "Render.h"
#include "ResManager.h"
#include <ctime>


LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("XNDON");

Scene* Render :: pScene = NULL;
vector<Sprite> Render :: sceneObject;
int Render :: dTime = NULL;

std::map<wstring, Image* > ResManager :: image_map;
bool	keys[256];	// Array Used For The Keyboard Routine

void OnPaint(HDC hdc);		
int lastTime = 0;
int dt = 0;
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
       ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst=hInstance;
	
	/*<----- GdiPlus ���� ----->*/
	ULONG_PTR gpToken;
    Gdiplus::GdiplusStartupInput gpsi;
    if ( Gdiplus::GdiplusStartup(&gpToken,&gpsi,NULL) != Gdiplus::Ok) {
		MessageBox(NULL,TEXT("GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�."),
		TEXT("�˸�"),MB_OK);
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
//		HDC hdc = GetDC(hWnd);
//		OnPaint(hdc);		
		TranslateMessage(&Message);
		DispatchMessage(&Message);
    }

	/*<----- GDI+ ���� ----->*/
	Gdiplus::GdiplusShutdown(gpToken);
	/*<--------------------->*/

	return (int)Message.wParam;
}
 
void OnPaint(HDC hdc)
{
     Graphics G(hdc);
     Gdiplus::Pen P( Gdiplus::Color(255,0,0,255),5);
 
     G.DrawEllipse(&P,rand()%500,rand()%500,300,200);
}


//void CALLBACK update(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
void update(int dt)
{
	HDC hdc = GetDC(hWndMain);
	Graphics G(hdc);
	using namespace Gdiplus;

    SolidBrush RESET( Color(255,255,255,255) );
	G.FillRectangle(&RESET,0,0,1280,760);

	Font F(L"����",20,FontStyleRegular,UnitPixel);

//	TCHAR *Hangul=L"�ѱ� ���ڿ�";
	TCHAR szWidth[128];
	RectF bound;
	SolidBrush B(Color(0,0,0));
//	G.DrawString(Hangul,-1,&F,PointF(0,00),&B);
//	G.MeasureString(Hangul,-1,&F,PointF(0,0),&bound);
	swprintf(szWidth,TEXT("dwTime:%u, ������ : %.2lf"), dt, 1000.0/(dt) );
	
	
	
	
	G.DrawString(szWidth,-1,&F, PointF(0,6),&B);

//	ReleaseDC(hWndMain, hdc);

//	Render::draw(hdc);

//	Render::sceneUpdate( );
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
     HDC hdc;
     PAINTSTRUCT ps;
	
	 map<WPARAM , BOOL> keydownmap;


	 static HANDLE hTimer;


     switch (iMessage) {
     case WM_CREATE:
          hWndMain = hWnd;
		 
		  // SetTimer() ���� Ÿ�̸� ��ġ, KillTimer() ���� Ÿ�̸� ����
		  // �켱������ �����Ƿ� ��Ȯ���� ���ؼ��� Ÿ�̸� �ݹ� �Լ� ��� => �׹�° ���ڿ� �ݹ��Լ� ����
		  hTimer= (HANDLE) SetTimer( hWnd, 1, 30, NULL );
          
		  
		  return 0;

	 case WM_KEYUP:
		 keys[wParam] = FALSE;
		 return 0;

		  return 0;
	 case WM_KEYDOWN:

		  keys[wParam] =TRUE;

		  return 0;
	case WM_TIMER:
		dt = clock() - lastTime;
		lastTime = clock();
		Render :: sceneUpdate( dt );		
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

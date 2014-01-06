#include "main.h"
#include "Render.h"
#include "InputController.h"
#include "ResManager.h"

#include <tchar.h>


LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); 
HINSTANCE g_hInst; // 핸들 인스턴스 , H 로 시작하는 자료형은 다 핸들

/*<--- 프로그램 윈도우 타이틀 정의 -->*/
LPCTSTR lpszClass = TEXT("XNDON"); // TEXT("문자") => L"문자" => _T("문자");

HWND hWndMain; // HWND : 윈도우 핸들을 담는 전용 타입, 유사) HANDLE : 범용핸들 타입
// hWND 가 전역(static)일 시 제대로 작동 안함


Scene* Render :: pScene = NULL;
vector<Sprite*> Render :: sceneObject;
int Render :: dTime = NULL;

CachedBitmap* Render :: pCBit = NULL;
bool InputController :: keys[256];
std::map<wstring, Image* > ResManager :: image_map;

void OnPaint(HDC hdc);		
int lastTime = 0;
int dt = 0;





// 우리가 Console 에서 사용하던 int main 과 유사한, 윈도우 창을 만드는 winMain
// winMain 기본인자는 아래와 같다.
// WinMain 으로 프로그램을 시작하며 실질적인 처리는 WndProc 함수에서 한다.
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
       ,LPSTR lpszCmdParam,int nCmdShow) 
{
	HWND hWnd;
    MSG Message;
    
    g_hInst = hInstance;
	
	/*<----- GdiPlus 시작 ----->*/
	ULONG_PTR gpToken;
    Gdiplus::GdiplusStartupInput gpsi;
    if ( Gdiplus::GdiplusStartup(&gpToken,&gpsi,NULL) != Gdiplus::Ok) {
		MessageBox(NULL,TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."),
		TEXT("알림"),MB_OK);
		return 0;
	} 
	/*<------------------------>*/
 

	/*<--- 윈도우( 입력과 출력을 할 수 있도록 해준다.) 클래스 --->*/
    WNDCLASS WndClass;

	WndClass.cbClsExtra=0;
    WndClass.cbWndExtra=0; 
    WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1); //윈도우 배경색상 지정
	WndClass.hCursor = LoadCursor(NULL,IDC_ARROW); // 마우스 커서
    WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION); // 최소화시 출력 아이콘
	WndClass.hInstance = hInstance; // 윈도우 클래스를 사용하는 프로그램의 번호, WinMain의 인자값 사용
	WndClass.lpfnWndProc = WndProc; // 윈도우의 메세지처리함수 지정, 관습적으로 이름 WndProc 사용
	WndClass.lpszClassName = lpszClass; // 윈도우 클래스의 이름 정의 : 윈도우의 이름
	WndClass.lpszMenuName=NULL; // 프로그램이 사용할 메뉴 지정, 코드로 만드는 것이 아닌 리소스 에디터에 의해 만들어 진 후 링크시 합쳐지도록. NULL 은 사용하지 않음
	WndClass.style=CS_HREDRAW | CS_VREDRAW; // 윈도우가 수직, 수평으로 크기가 변할 경우 다시 그린다.
	RegisterClass(&WndClass); // 윈도우 클래스 등록

	// 윈도우 생성
	hWnd = CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW, 
		0 , 0, CL_WIN_WIDTH_PIXEL, CL_WIN_HEIGHT_PIXEL, NULL,(HMENU)NULL,hInstance,NULL);
	/*<--- 윈도우 클래스 등록 및 생성 완료 --->*/

	
	ShowWindow(hWnd,nCmdShow);
 
	Scene scene;
	Render::setScene(&scene);	

    while ( GetMessage(&Message,NULL,0,0) )
	{
//		HDC hdc = GetDC(hWnd);
//		OnPaint(hdc);		
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

	Font F(L"굴림",20,FontStyleRegular,UnitPixel);

//	TCHAR *Hangul=L"한글 문자열";
	TCHAR szWidth[128];
	RectF bound;
	SolidBrush B(Color(0,0,0));
//	G.DrawString(Hangul,-1,&F,PointF(0,00),&B);
//	G.MeasureString(Hangul,-1,&F,PointF(0,0),&bound);
	swprintf(szWidth,TEXT("dwTime:%u, 프레임 : %.2lf"), dt, 1000.0/(dt) );
	
	
	
	
	G.DrawString(szWidth,-1,&F, PointF(0,6),&B);

//	ReleaseDC(hWndMain, hdc);

//	Render::draw(hdc);

//	Render::sceneUpdate( );
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
     HDC hdc;
     PAINTSTRUCT ps;
	
	 
	 /*마우스 출력 쓸꺼면 쓰세요
	 vector<LPARAM> leftmousemove ;
	 vector<LPARAM> rightmousemove;
	 bool leftdown = FALSE;
	 bool rightdown = FALSE;
	 */
	 static HANDLE hTimer;
     switch (iMessage) {
     case WM_CREATE:
		hWndMain = hWnd;
		hdc = GetDC(hWnd);		 
		// SetTimer() 으로 타이머 설치, KillTimer() 으로 타이머 해제
		// 우선순위가 낮으므로 정확도를 위해서는 타이머 콜백 함수 사용 => 네번째 인자에 콜백함수 포함
		hTimer= (HANDLE) SetTimer( hWnd, 1, 30, NULL );
      	return 0;

	 case WM_KEYUP:
		InputController::keys[wParam] = FALSE;
		
		
		
		return 0;
	 case WM_KEYDOWN:
		InputController::keys[wParam] = TRUE;
		return 0;
	/* 마우스 출력 쓸꺼면 쓰세요
	 case WM_LBUTTONDOWN:
		 leftdown = TRUE;
		 leftmousemove.clear();
		 leftmousemove.push_back(lParam);
		 return 0;

	 case WM_LBUTTONUP:
		 leftdown = FALSE;

		
		 return 0;

	 case WM_MOUSEMOVE:
		 if(leftdown==TRUE)
			leftmousemove.push_back(lParam);
		 return 0;
	*/
	case WM_TIMER:
		hdc = GetDC(hWnd);		 

		dt = clock() - lastTime;
		lastTime = clock();
//		update( dt );
		Render :: sceneUpdate( dt );
		Render::draw(hdc);

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

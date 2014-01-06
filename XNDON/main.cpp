#include "main.h"
#include "Render.h"
#include "InputController.h"
#include "ResManager.h"

#include <tchar.h>


LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); 
HINSTANCE g_hInst; // �ڵ� �ν��Ͻ� , H �� �����ϴ� �ڷ����� �� �ڵ�

/*<--- ���α׷� ������ Ÿ��Ʋ ���� -->*/
LPCTSTR lpszClass = TEXT("XNDON"); // TEXT("����") => L"����" => _T("����");

HWND hWndMain; // HWND : ������ �ڵ��� ��� ���� Ÿ��, ����) HANDLE : �����ڵ� Ÿ��
// hWND �� ����(static)�� �� ����� �۵� ����


Scene* Render :: pScene = NULL;
vector<Sprite*> Render :: sceneObject;
int Render :: dTime = NULL;

CachedBitmap* Render :: pCBit = NULL;
bool InputController :: keys[256];
std::map<wstring, Image* > ResManager :: image_map;

void OnPaint(HDC hdc);		
int lastTime = 0;
int dt = 0;





// �츮�� Console ���� ����ϴ� int main �� ������, ������ â�� ����� winMain
// winMain �⺻���ڴ� �Ʒ��� ����.
// WinMain ���� ���α׷��� �����ϸ� �������� ó���� WndProc �Լ����� �Ѵ�.
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
       ,LPSTR lpszCmdParam,int nCmdShow) 
{
	g_hInst = hInstance;
	
	/*<--- ������( �Է°� ����� �� �� �ֵ��� ���ش�.) Ŭ���� --->*/
    WNDCLASS WndClass;

	WndClass.cbClsExtra=0;
    WndClass.cbWndExtra=0; 
    WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1); //������ ������ ����
	WndClass.hCursor = LoadCursor(NULL,IDC_ARROW); // ���콺 Ŀ��
    WndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION); // �ּ�ȭ�� ��� ������
	WndClass.hInstance = hInstance; // ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ, WinMain�� ���ڰ� ���
	WndClass.lpfnWndProc = WndProc; // �������� �޼���ó���Լ� ����, ���������� �̸� WndProc ���
	WndClass.lpszClassName = lpszClass; // ������ Ŭ������ �̸� ���� : �������� �̸�
	WndClass.lpszMenuName=NULL; // ���α׷��� ����� �޴� ����, �ڵ�� ����� ���� �ƴ� ���ҽ� �����Ϳ� ���� ����� �� �� ��ũ�� ����������. NULL �� ������� ����
	WndClass.style=CS_HREDRAW | CS_VREDRAW; // �����찡 ����, �������� ũ�Ⱑ ���� ��� �ٽ� �׸���.
	RegisterClass(&WndClass); // ������ Ŭ���� ���

	// ������ ����
	HWND hWnd;
	hWnd = CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW, 
		0 , 0, CL_WIN_WIDTH_PIXEL, CL_WIN_HEIGHT_PIXEL, NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	/*<--- ������ Ŭ���� ��� �� ���� �Ϸ� --->*/
	
	/*<----- GdiPlus ���� ----->*/
	ULONG_PTR gpToken;
    Gdiplus::GdiplusStartupInput gpsi;
    if ( Gdiplus::GdiplusStartup(&gpToken,&gpsi,NULL) != Gdiplus::Ok) {
		MessageBox(NULL,TEXT("GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�."),
		TEXT("�˸�"),MB_OK);
		return 0;
	} 
	/*<------------------------>*/
	
 
	Scene scene;
	Render::setScene(&scene);	


	MSG Message;
    while ( GetMessage(&Message,NULL,0,0) )
	{
//		TranslateMessage(&Message); //	TranslateMessage �Լ��� ���޵� �޽����� WM_KEYDOWN������ ������ Ű�� ����Ű���� �˻��� ���� ������ ���� ��� WM_CHAR �޽����� ����� �޽��� ť�� �����̴� ������ �Ѵ�. ���� ���� �Է��� �ƴ� ���� �ƹ� �ϵ� ���� ������ �� �޽����� DispatchMessage �Լ��� ���� WndProc���� ��������.
		DispatchMessage(&Message);
    }

	// BOOL GetMessage( LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax); 
    // �� �Լ��� �ý����� �����ϴ� �޽��� ť���� �޽����� �о���δ�. �о���� �޽����� ù��° �μ��� �����ϴ� MSG ����ü�� ����ȴ�. �� �Լ��� �о���� �޽����� ���α׷��� �����϶�� WM_QUIT�� ��� False�� �����ϸ� �� ���� �޽����̸� True�� �����Ѵ�. ���� WM_QUIT �޽����� ������ ������, �� ���α׷��� ����� ������ ��ü while ������ ��� ����ȴ�. ������ �� ���� �μ��� �о���� �޽����� ������ �����ϴµ� �� ������ �����Ƿ� �ϴ� �����ϱ�� �Ѵ�.

	// BOOL TranslateMessage( CONST MSG *lpMsg); 
	// Ű���� �Է� �޽����� �����Ͽ� ���α׷����� ���� �� �� �ֵ��� �� �ش�. ��������� Ű������ � Ű�� �������ٰų� �������� �� Ű���� �޽����� �߻���Ű�µ� �� �Լ��� Ű������ ����(WM_KEYDOWN)�� ������(WM_KEYUP)�� ���������� �߻��� �� ���ڰ� �ԷµǾ��ٴ� �޽���(WM_CHAR)�� ����� ������ �Ѵ�. ���� ��� AŰ�� ���� �� �ٽ� AŰ�� ���� A���ڰ� �ԷµǾ��ٴ� �޽����� ����� ����.

	// LONG DispatchMessage( CONST MSG *lpmsg); 
	// �ý��� �޽��� ť���� ���� �޽����� ���α׷��� �޽��� ó�� �Լ�(WndProc)�� �����Ѵ�. �� �Լ��� ���� �޽����� ���α׷����� ���޵Ǹ� ���α׷������� ���޵� �޽����� �����Ͽ� ���� ������ �����ϰ� �ȴ�.
	// �޽��� �������� �ϴ� ���� �޽����� ������, �ʿ��� ��� �ణ ���¸� �ٲ� �� ���� ���α׷����� �����ϴ� �� ���̴�. �� ������ WM_QUIT �޽����� ���޵� ������, �� ���α׷��� ����ɶ����� �ݺ��ȴ�. �ᱹ �޽��� ������ �ϴ� ���̶� �޽��� ť���� �޽����� ���� �޽��� ó�� �Լ��� �����ִ� �� ���̴�.
	// ���� �޽��� ó���� ������ �޽��� ó�� �Լ�(WndProc)���� �����Ѵ�. �޽����� �ý����� ��ȭ�� ���� �����̸� MSG��� ����ü�� �����ȴ�. MSG ����ü�� ������ ���� ���ǵǾ� �ִ�.

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

	 /*���콺 ��� ������ ������
	 vector<LPARAM> leftmousemove ;
	 vector<LPARAM> rightmousemove;
	 bool leftdown = FALSE;
	 bool rightdown = FALSE;
	 */

	 HANDLE hTimer;
     switch (iMessage) {
     case WM_CREATE:
		hWndMain = hWnd;
		hdc = GetDC(hWnd);		 
		// SetTimer() ���� Ÿ�̸� ��ġ, KillTimer() ���� Ÿ�̸� ����
		// �켱������ �����Ƿ� ��Ȯ���� ���ؼ��� Ÿ�̸� �ݹ� �Լ� ��� => �׹�° ���ڿ� �ݹ��Լ� ����
		hTimer= (HANDLE) SetTimer( hWnd, 1, 30, NULL );
      	return 0;

	 case WM_KEYUP:
		InputController::keys[wParam] = FALSE;
		
		
		
		return 0;
	 case WM_KEYDOWN:
		InputController::keys[wParam] = TRUE;
		return 0;
	/* ���콺 ��� ������ ������
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

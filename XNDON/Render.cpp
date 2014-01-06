#include "Render.h"

extern HWND hWndMain;

void Render :: setScene(XDScene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
	using namespace Gdiplus;
	Graphics G(hdc);

	if (pCBit == NULL) {
		Render :: sceneUpdate();
	}
	G.DrawCachedBitmap(pCBit,0,0);
	
}

void Render :: sceneUpdate(int dt){
	dTime = dt;
	pScene->getPlayer()->update(dt);
	list<XDSprite*> missiles = pScene->getMissiles();
	for(list<XDSprite*>::iterator itr = missiles.begin(); itr != missiles.end(); itr++)
		(*itr)->update(dt);



	sceneUpdate();
}

Render::Render(void){	}
Render::~Render(void){	 }

void Render :: sceneUpdate()
{
	using namespace Gdiplus;
	if ( pScene == NULL ) 
		return ;

	sceneObject.clear();
	sceneObject.push_back( pScene->getPlayer() );  
	for(list<XDSprite*>::iterator itr = pScene->getMissileBegin(); itr != pScene->getMissileEnd(); itr++)
		sceneObject.push_back( (Missile *) *itr );
	


	// 더블버퍼링 시작
	Graphics G(hWndMain);
	RECT crt;
	GetClientRect(hWndMain,&crt);   //화면의 사각형 얻는다
	Bitmap *pBit=new Bitmap(crt.right,crt.bottom,&G);   //화면크기의 비트맵 생성(그림을 임시그릴 영역
	Graphics *memG=new Graphics(pBit);

	SolidBrush RESET( Color(255,255,255,255) );
	memG->FillRectangle(&RESET,0,0,crt.right,crt.bottom);

	// sort(sceneObject.비긴 , 엔드.,  z 축으로 정렬 ) 
	for(vector<XDSprite*>::iterator itr = sceneObject.begin(); itr != sceneObject.cend(); itr++ )
	{
		(*itr)->drawSprite(*memG);
	}

	/*if (pCBit == NULL) {  //표시할 그림이없는 경우 그림 만들기
		UpdateScreen();
	}*/

	Font F(L"굴림",20,FontStyleRegular,UnitPixel);
	TCHAR szWidth[128];
	SolidBrush B(Color(0,0,0));
	swprintf(szWidth,TEXT("dTime:%u, 프레임 : %.2lf"), dTime, 1000.0/(dTime) );
	memG->DrawString(szWidth,-1,&F, PointF(0,6),&B); 


	if (pCBit) {               //이전에 화면에 표시되는 비트맵 비우기
		delete pCBit;
	}

	pCBit=new CachedBitmap(pBit,&G);  //새로 그린 그림을 화면에 올리는 비트맵으로 교체
	delete pBit;                      //새로 그린 그림 저장장소 해방
	delete memG;                      //그래픽 객체 소거

	InvalidateRect(hWndMain,NULL,FALSE);   //변한 화면 바꾸기를 위하여 이전에 남아있는 화면을 삭제한다.
}

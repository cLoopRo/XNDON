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
	


	// ������۸� ����
	Graphics G(hWndMain);
	RECT crt;
	GetClientRect(hWndMain,&crt);   //ȭ���� �簢�� ��´�
	Bitmap *pBit=new Bitmap(crt.right,crt.bottom,&G);   //ȭ��ũ���� ��Ʈ�� ����(�׸��� �ӽñ׸� ����
	Graphics *memG=new Graphics(pBit);

	SolidBrush RESET( Color(255,255,255,255) );
	memG->FillRectangle(&RESET,0,0,crt.right,crt.bottom);

	// sort(sceneObject.��� , ����.,  z ������ ���� ) 
	for(vector<XDSprite*>::iterator itr = sceneObject.begin(); itr != sceneObject.cend(); itr++ )
	{
		(*itr)->drawSprite(*memG);
	}

	/*if (pCBit == NULL) {  //ǥ���� �׸��̾��� ��� �׸� �����
		UpdateScreen();
	}*/

	Font F(L"����",20,FontStyleRegular,UnitPixel);
	TCHAR szWidth[128];
	SolidBrush B(Color(0,0,0));
	swprintf(szWidth,TEXT("dTime:%u, ������ : %.2lf"), dTime, 1000.0/(dTime) );
	memG->DrawString(szWidth,-1,&F, PointF(0,6),&B); 


	if (pCBit) {               //������ ȭ�鿡 ǥ�õǴ� ��Ʈ�� ����
		delete pCBit;
	}

	pCBit=new CachedBitmap(pBit,&G);  //���� �׸� �׸��� ȭ�鿡 �ø��� ��Ʈ������ ��ü
	delete pBit;                      //���� �׸� �׸� ������� �ع�
	delete memG;                      //�׷��� ��ü �Ұ�

	InvalidateRect(hWndMain,NULL,FALSE);   //���� ȭ�� �ٲٱ⸦ ���Ͽ� ������ �����ִ� ȭ���� �����Ѵ�.
}

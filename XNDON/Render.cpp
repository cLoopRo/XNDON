#include "Render.h"

extern HWND hWndMain;

void Render :: setScene(Scene* _Scene){
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
	list<Sprite*> missiles = pScene->getMissiles();
	list<Sprite*> gobs = pScene->getGobs();
	for(list<Sprite*>::iterator itr = missiles.begin(); itr != missiles.end(); itr++)
		(*itr)->update(dt);

	for(list<Sprite*>::iterator itr2 = gobs.begin(); itr2 != gobs.end(); itr2++)
		(*itr2)->update(dt);

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
	for(list<Sprite*>::iterator itr = pScene->getMissileBegin(); itr != pScene->getMissileEnd(); itr++)
		sceneObject.push_back( (Missile *) *itr );
	for(list<Sprite*>::iterator itr2 = pScene->getGobBegin(); itr2 != pScene->getGobEnd(); itr2++)
		sceneObject.push_back( (Gob *) *itr2 );


	// ������۸� ����
	Graphics G(hWndMain);
	RECT crt;
	GetClientRect(hWndMain,&crt);   //ȭ���� �簢�� ��´�
	Bitmap *pBit=new Bitmap(crt.right,crt.bottom,&G);   //ȭ��ũ���� ��Ʈ�� ����(�׸��� �ӽñ׸� ����
	Graphics *memG=new Graphics(pBit);

	SolidBrush RESET( Color(255,255,255,255) );
	memG->FillRectangle(&RESET,0,0,crt.right,crt.bottom);

	// sort(sceneObject.��� , ����.,  z ������ ���� ) 
	for(vector<Sprite*>::iterator itr = sceneObject.begin(); itr != sceneObject.cend(); itr++ )
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

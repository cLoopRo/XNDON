#include "Render.h"

extern HWND hWndMain;

void Render :: set_Scene(Scene* _Scene){
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

	if ( Render::keys[37]  ) // left
		pScene->Player.moveLeft(dt);
	if ( Render::keys[38]  ) // up
		pScene->Player.moveUp(dt);
	if ( Render::keys[39] ) // right
		pScene->Player.moveRight(dt);
	if ( Render::keys[40] ) // down
		pScene->Player.moveDown(dt);

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
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ù��° ���ͷ�����, ȭ�������� ������ ���ͷ����� ); // 
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ���� ���ͷ�����, ȭ�������� ���� ���ͷ����� ); // 
	


	// ������۸� ����
	Graphics G(hWndMain);
	RECT crt;
	GetClientRect(hWndMain,&crt);   //ȭ���� �簢�� ��´�
	Bitmap *pBit=new Bitmap(crt.right,crt.bottom,&G);   //ȭ��ũ���� ��Ʈ�� ����(�׸��� �ӽñ׸� ����
	Graphics *memG=new Graphics(pBit);

	SolidBrush RESET( Color(255,255,255,255) );
	memG->FillRectangle(&RESET,0,0,crt.right,crt.bottom);

	// sort(sceneObject.��� , ����.,  z ������ ���� ) 
	//for(vector<Sprite>::iterator itr = sceneObject.begin(); itr != sceneObject.cend(); itr++ )
	{
		sceneObject[0]->drawPlayer(*memG);
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
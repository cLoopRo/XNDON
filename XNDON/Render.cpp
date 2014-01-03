#include "Render.h"


void Render :: setScene(Scene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
	using namespace Gdiplus;
	;
	if ( pScene == NULL ) 
		return ;
	sceneObject.clear();
	sceneObject.push_back( pScene->getPlayer() );  
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ù��° ���ͷ�����, ȭ�������� ������ ���ͷ����� ); // 
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ���� ���ͷ�����, ȭ�������� ���� ���ͷ����� ); // 
	Graphics G(hdc);
	
	SolidBrush RESET( Color(255,255,255,255) );
	G.FillRectangle(&RESET,0,0,1280,760);

	// ������۸� 
	// sort(sceneObject.��� , ����.,  z ������ ���� ) 
	//for(vector<Sprite>::iterator itr = sceneObject.begin(); itr != sceneObject.cend(); itr++ )
	{
		sceneObject[0]->drawPlayer(G);
	}

	Font F(L"����",20,FontStyleRegular,UnitPixel);
	TCHAR szWidth[128];
	SolidBrush B(Color(0,0,0));
	swprintf(szWidth,TEXT("dTime:%u, ������ : %.2lf"), dTime, 1000.0/(dTime) );
	G.DrawString(szWidth,-1,&F, PointF(0,6),&B); 

}

void Render :: sceneUpdate(int dt){
	dTime = dt;	
	pScene->getPlayer()->update(dt);
}

Render::Render(void){	}
Render::~Render(void){	 }

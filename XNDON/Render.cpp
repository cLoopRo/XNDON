#include "Render.h"

void Render :: set_Scene(Scene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
	using namespace Gdiplus;
	if ( pScene == NULL ) 
		return ;

	sceneObject.push_back( pScene->getPlayer() ); // 
	// sceneObject.insert( sceneObject.cbegin(), 화면상몬스터의 첫번째 이터레이터, 화면상몬스터의 마지막 이터레이터 ); // 
	// sceneObject.insert( sceneObject.cbegin(), 화면상몬스터의 공격 이터레이터, 화면상몬스터의 공격 이터레이터 ); // 
	Graphics G(hdc);
	
	// 더블버퍼링 
	// sort(sceneObject.비긴 , 엔드.,  z 축으로 정렬 ) 
	for(vector<Sprite>::const_iterator itr = sceneObject.cbegin(); itr != sceneObject.cend(); itr++ )
	{
//		G.DrawImage( itr->getImage(), ;
	}
	
	Font F(L"굴림",20,FontStyleRegular,UnitPixel);
	TCHAR szWidth[128];
	SolidBrush B(Color(0,0,0));
	swprintf(szWidth,TEXT("dwTime:%u, 프레임 : %.2lf"), dTime, 1000.0/(dTime) );
	G.DrawString(szWidth,-1,&F, PointF(0,6),&B); 

}

void Render :: sceneUpdate(int dt){
	


	
}

Render::Render(void){	}
Render::~Render(void){	}

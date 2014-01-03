#include "Render.h"

void Render :: set_Scene(Scene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
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
//		G.DrawImage( itr->현재 보여줘야되는 상태 );
	}
	
	// 
}

void Render :: sceneUpdate( ){
	
}

Render::Render(void){	}
Render::~Render(void){	}

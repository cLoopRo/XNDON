#include "Render.h"

void Render :: set_Scene(Scene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
	if ( pScene == NULL ) 
		return ;

	sceneObject.push_back( pScene->getPlayer() ); // 
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ù��° ���ͷ�����, ȭ�������� ������ ���ͷ����� ); // 
	// sceneObject.insert( sceneObject.cbegin(), ȭ�������� ���� ���ͷ�����, ȭ�������� ���� ���ͷ����� ); // 
	Graphics G(hdc);
	
	// ������۸� 
	// sort(sceneObject.��� , ����.,  z ������ ���� ) 
	for(vector<Sprite>::const_iterator itr = sceneObject.cbegin(); itr != sceneObject.cend(); itr++ )
	{
//		G.DrawImage( itr->getImage(), ;
	}
	
	// 
}

void Render :: sceneUpdate( ){
	
}

Render::Render(void){	}
Render::~Render(void){	}

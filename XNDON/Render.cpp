#include "Render.h"

void Render :: set_Scene(Scene* _Scene){
	pScene = _Scene;
}

void Render :: draw(HDC hdc){
	if ( pScene == NULL ) 
		return ;

	sceneObject.push_back( pScene->getPlayer() );
	
	Graphics G(hdc);
	
	for(vector<Sprite>::const_iterator itr = sceneObject.cbegin(); itr != sceneObject.cend(); itr++ )
	{
//		G.DrawImage(  );
	}
	
}

void Render :: sceneUpdate( ){
	
}

Render::Render(void){	}
Render::~Render(void){	}

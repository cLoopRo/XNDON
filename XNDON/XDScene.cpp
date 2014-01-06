#include "XDScene.h"

XDScene :: XDScene( )
{
	player = new Player( );
	missile.push_back( new Missile() );
	missile.push_back( new Missile() );

}


XDScene::~XDScene(void)
{

}

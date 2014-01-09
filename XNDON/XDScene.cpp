#include "XDScene.h"

XDScene :: XDScene( )
{
	_player = new Player( );
	_missile.push_back( new Missile() );
	_missile.push_back( new Missile() );

}


XDScene::~XDScene(void)
{

}

#include "Scene.h"

Scene :: Scene( )
{
	player = new Player( );
	missile.push_back( new Missile() );
	missile.push_back( new Missile() );

}


Scene::~Scene(void)
{

}

#include "Scene.h"

Scene :: Scene( )
{
	player = new Player( );
	missile.push_back( new Missile() );
	
	gob.push_back( new Gob(player -> getPosition()) );


}


Scene::~Scene(void)
{

}

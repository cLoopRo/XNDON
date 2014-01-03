#pragma once
#include "Sprite.h"

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);
	
	Sprite getPlayer(){	return Player;		}
	void update();
private:
	Sprite Player;
	

};

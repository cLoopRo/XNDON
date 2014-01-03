#pragma once
#include "Sprite.h"
#include "main.h"

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);
	
	Sprite getPlayer(){	return Player;		}
	

private:
	Sprite Player;
//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  splice
//  list<Sprite> OtherPlayer;

};

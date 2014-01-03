#pragma once
#include "Sprite.h"
#include "main.h"
#include "Player.h"

class Scene
{
public:
	Scene( );
	virtual ~Scene(void);
	
	Player* getPlayer(){	return &Player;	}
	
	void Update(int dt);
	friend class Render;
private:
	Player Player;

//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

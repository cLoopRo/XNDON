#pragma once
#include "main.h"
#include "Player.h"

class Scene
{
public:
	
	Scene( );
	virtual ~Scene( );
	Player* getPlayer(){ return player;	}
	void Update(int dt);

private:
	Player* player;

//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

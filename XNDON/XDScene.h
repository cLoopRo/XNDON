#pragma once
#include "main.h"
#include "Player.h"
#include "Missile.h"

class XDScene
{
public:
	
	XDScene( );
	virtual ~XDScene( );
	Player* getPlayer(){ return (Player*) player;	}
	list<Sprite*>& getMissiles( ){	return missile;	};
	
	list<Sprite*>::iterator getMissileBegin( ){ return missile.begin();	}
	list<Sprite*>::iterator getMissileEnd( ){ return missile.end();	}

	void Update(int dt);

private:
	XDSprite* player;
	list<Sprite*> missile;

//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

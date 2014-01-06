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
	list<XDSprite*>& getMissiles( ){	return missile;	};
	
	list<XDSprite*>::iterator getMissileBegin( ){ return missile.begin();	}
	list<XDSprite*>::iterator getMissileEnd( ){ return missile.end();	}

	void Update(int dt);

private:
	XDSprite* player;
	list<XDSprite*> missile;

//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

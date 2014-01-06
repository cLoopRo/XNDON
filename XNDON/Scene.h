#pragma once
#include "main.h"
#include "Player.h"
#include "Missile.h"
#include "Gob.h"

class Scene
{
public:
	
	Scene( );
	virtual ~Scene( );
	Player* getPlayer(){ return (Player*) player;	}
	list<Sprite*>& getMissiles( ){	return missile;	};
	list<Gob*>& getGobs( ){	return gob;	};
	
	list<Sprite*>::iterator getMissileBegin( ){ return missile.begin();	}
	list<Sprite*>::iterator getMissileEnd( ){ return missile.end();	}

	list<Gob*>::iterator getGobBegin( ){ return gob.begin();	}
	list<Gob*>::iterator getGobEnd( ){ return gob.end();	}

	void Update(int dt);

private:
	Sprite* player;
	list<Sprite*> missile;

	list<Gob*> gob;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

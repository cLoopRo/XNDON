#pragma once
#include "main.h"
#include "Player.h"
#include "Missile.h"

class XDScene
{
public:
	
	XDScene( );
	virtual ~XDScene( );
	Player* getPlayer(){ return (Player*) _player;	}
	list<XDSprite*>& getMissiles( ){	return _missile;	};
	
	list<XDSprite*>::iterator getMissileBegin( ){ return _missile.begin();	}
	list<XDSprite*>::iterator getMissileEnd( ){ return _missile.end();	}

	void Update(int dt);

	bool isCollide(XDSprite* _A, XDSprite* _B)
	{


		return true;
	}

	void Collide_Update( ){
		

		// 몬스터와 플레이어간의 충돌
		for(list<XDSprite*>::iterator itr = _live_Monster.begin(); itr != _live_Monster.end(); itr++)
		{
			if ( isCollide( _player, *itr ) )
			{
			
			}
		}


	}

private:
	XDSprite* _player;
	list<XDSprite*> _players;
	list<XDSprite*> _missile;
	list<XDSprite*> _live_Monster;


//	list<Sprite> Monster;
//	list<Sprite> DeadMonster;
//  list<Sprite> Attack;
//  list<Sprite> Attacked;
//  list<Sprite> OtherPlayer;

};

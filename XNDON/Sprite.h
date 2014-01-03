#pragma once
#include "main.h"

class Sprite
{
public:
	Sprite( );
	Sprite(int _MaxHP, int _HP, const Coord& _Position, const Coord& _Velocity); 

	bool isControll( );

	void updateState(int dt);
	int getState( );
	Image* getImage();

	void setHp(int _Hp);
	void addHP(int _Hp);
	void delHP(int _Hp);
	void getHP( );

	void moveLeft( );
	void moveRight( );
	void moveUp( );
	void moveDown( ); 

	virtual ~Sprite(void);


protected:
	int is_controll;

	int max_hp;
	int hp;
	int state;

	Coord position; // Make Getter Setter
	Coord velocity; // Make Getter Setter

};

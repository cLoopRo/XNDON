#pragma once
#include "main.h"
#include "ResManager.h"

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

	void setimg(wstring _Path);  //경로를 받아 해당 이미지가 저장된 주소를 이 클래스의 img포인터에 저장시킨다.
	void draw(Graphics* memG);   //그림을 그린다. 이때 더블 버퍼링을 이용하므로 버퍼(즉 비트맵)을 받아서 거기에 그림을 그린다.

	virtual ~Sprite(void);


protected:
	int is_controll;

	int max_hp;
	int hp;
	int state;

	Image* img;  //이미지포인터

	Coord position; // Make Getter Setter
	Coord velocity; // Make Getter Setter

};

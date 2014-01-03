#pragma once
#include "main.h"
#include "ResManager.h"

class Sprite
{
public:
	Sprite( ) {
		is_controll = 1;
		max_hp = 1;
		hp = 1;
		state = 0; //??
		position = Coord();
		velocity = Coord();
	}
	Sprite(int _MaxHP, int _HP, const Coord& _Position, const Coord& _Velocity) {
		is_controll = 1;
		max_hp = _MaxHP;
		hp = _HP;
		state = 0; //??
		position.X = _Position.X;
		position.Y = _Position.Y;
		position.Z = _Position.Z;
		velocity.X = _Velocity.X;
		velocity.Y = _Velocity.Y;
		velocity.Z = _Velocity.Z;
	}
	Sprite(int _CONTROLL, int _MaxHP, int _HP, const Coord& _Position, const Coord& _Velocity) {
		is_controll = _CONTROLL;
		max_hp = _MaxHP;
		hp = _HP;
		state = 0; //??
		position.X = _Position.X;
		position.Y = _Position.Y;
		position.Z = _Position.Z;
		velocity.X = _Velocity.X;
		velocity.Y = _Velocity.Y;
		velocity.Z = _Velocity.Z;
	}
	Sprite(int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
		is_controll = 1;
		max_hp = _MaxHP;
		hp = _HP;
		state = 0; //??
		position = Coord(_PosX, _PosY, _PosZ);
		velocity = Coord(_VelZ, _VelY, _VelZ);
	}
	Sprite(int _CONTROLL, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
		is_controll = _CONTROLL;
		max_hp = _MaxHP;
		hp = _HP;
		state = 0; //??
		position = Coord(_PosX, _PosY, _PosZ);
		velocity = Coord(_VelZ, _VelY, _VelZ);
	}

	bool isControll( ) {return is_controll==1;}
	void setControll(bool _CONTROLL) {is_controll = _CONTROLL; return;}

	void updateState(int dt) {
		//I don't know what to do
	}
	int getState( ) {return state;}

	void setHp(int _Hp) {
		hp = _Hp;
		return;
	}
	void addHP(int _Hp) {
		hp += _Hp;
		return;
	}
	void delHP(int _Hp) {
		hp -= _Hp;
		return;
	}
	int getHP( ) {return hp;}

	int getMaxHp() {return max_hp;}
	void setMaxHp(int _MaxHp) {max_hp = _MaxHp; return;}

<<<<<<< HEAD
	void setimg(wstring _Path);  //경로를 받아 해당 이미지가 저장된 주소를 이 클래스의 img포인터에 저장시킨다.
	void draw(Graphics* memG);   //그림을 그린다. 이때 더블 버퍼링을 이용하므로 버퍼(즉 비트맵)을 받아서 거기에 그림을 그린다.

	virtual ~Sprite(void);
=======
	void moveLeft(int dt) {
		position.X -= velocity.X*dt;
		return;
	}
	void moveRight(int dt) {
		position.X += velocity.X*dt;
		return;
	}
	void moveUp(int dt) {
		position.Y -= velocity.Y*dt;
		return;
	}
	void moveDown(int dt) {
		position.Y += velocity.Y*dt;
		return;
	}
	/* void move(int dt) {
		position.X += velocity.X*dt;
		position.Y += velocity.Y*dt;
		return;
	} */

	int getPosX() {return position.X;}
	int getPosY() {return position.Y;}
	int getPosZ() {return position.Z;}
	int getVelX() {return velocity.X;}
	int getVelY() {return velocity.Y;}
	int getVelZ() {return velocity.Z;}
	void setPosX(int a) {position.X = a; return;}
	void setPosY(int a) {position.Y = a; return;}
	void setPosZ(int a) {position.Z = a; return;}
	void setVelX(int a) {velocity.X = a; return;}
	void setVelY(int a) {velocity.Y = a; return;}
	void setVelZ(int a) {velocity.Z = a; return;}
	const Coord& getPos() {return position;}
	const Coord& getVel() {return velocity;}
	void setPos(const Coord& _Position) {
		position.X = _Position.X;
		position.Y = _Position.Y;
		position.Z = _Position.Z;
		return;
	}
	void setVel(const Coord& _Velocity) {
		velocity.X = _Velocity.X;
		velocity.Y = _Velocity.Y;
		velocity.Z = _Velocity.Z;
	}
	void setPos(int a, int b, int c) {
		position = Coord(a, b, c);
		return;
	}
	void setVel(int a, int b, int c) {
		velocity = Coord(a, b, c);
		return;
	}

	virtual ~Sprite(void);  //..??
>>>>>>> e1afbaa5e5813ad080f42042273407c30804b78a


protected:
	//is_controll is 0 if it is already doing something
	//else 1
	int is_controll;

	int max_hp;
	int hp;
	int state;

	Image* img;  //이미지포인터

	Coord position; // Make Getter Setter
	Coord velocity; // Make Getter Setter

};

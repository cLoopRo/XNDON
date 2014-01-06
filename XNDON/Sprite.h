#pragma once
#include "main.h"
#include "ResManager.h"

class XDSprite
{
public:
	virtual void drawSprite( Graphics& G );
	virtual void update(int dt);
	XDSprite( );
	XDSprite(wstring _Path); 
	XDSprite(int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity);
	XDSprite(int _Controll, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity);
	XDSprite(int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ);
	XDSprite(int _Controll, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ);

	XDSprite(bool _Direction, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity);
	XDSprite(bool _Direction, int _Controll, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity);
	XDSprite(bool _Direction, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ);
	XDSprite(bool _Direction, int _Controll, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ);

	bool getDirection( ) {return direction;}
	void setDirection(bool _Direction) {direction = _Direction;}

	bool isControll( ) {return is_controll==1;}
	void setControll(bool _Controll) {is_controll = _Controll;}

	void updateState(int dt) {}  //I don't know what to do
	int getState( ) {return state;}

	void setHp(int _HP) {hp = _HP;}
	void addHP(int _HP) {hp += _HP;}
	void delHP(int _HP) {hp -= _HP;}
	int getHP( ) {return hp;}

	int getMaxHp( ) {return max_hp;}
	void setMaxHp(int _MaxHp) {max_hp = _MaxHp;}

	void setimg(wstring _Path);  //경로를 받아 해당 이미지가 저장된 주소를 이 클래스의 img포인터에 저장시킨다.
	void draw(Graphics* memG);   //그림을 그린다. 이때 더블 버퍼링을 이용하므로 버퍼(즉 비트맵)을 받아서 거기에 그림을 그린다.

	virtual ~XDSprite(void);

	void moveLeft(int dt) {position.X -= velocity.X*dt;}
	void moveRight(int dt) {position.X += velocity.X*dt;}
	void moveUp(int dt) {position.Y -= velocity.Y*dt;}
	void moveDown(int dt) {position.Y += velocity.Y*dt;}
	/* void move(int dt) {
		position.X += velocity.X*dt;
		position.Y += velocity.Y*dt;
		return;
	} */
	
	int getPositionX( ) {return position.X;}
	int getPositionY( ) {return position.Y;}
	int getPositionZ( ) {return position.Z;}
	int getVelocityX( ) {return velocity.X;}
	int getVelocityY( ) {return velocity.Y;}
	int getVelocityZ( ) {return velocity.Z;}
	void setPositionX(int _X) {position.X = _X;}
	void setPositionY(int _Y) {position.Y = _Y;}
	void setPositionZ(int _Z) {position.Z = _Z;}
	void setVelocityX(int _X) {velocity.X = _X;}
	void setVelocityY(int _Y) {velocity.Y = _Y;}
	void setVelocityZ(int _Z) {velocity.Z = _Z;}
	const Vector3& getPosition( ) {return position;}
	const Vector3& getVelocity( ) {return velocity;}
	void setPosition(const Vector3& _Position) {
		position.X = _Position.X;
		position.Y = _Position.Y;
		position.Z = _Position.Z;
	}
	void setVelocity(const Vector3& _Velocity) {
		velocity.X = _Velocity.X;
		velocity.Y = _Velocity.Y;
		velocity.Z = _Velocity.Z;
	}
	void setPosition(int _X, int _Y, int _Z) {position = Vector3(_X, _Y, _Z);}
	void setVelocity(int _X, int _Y, int _Z) {velocity = Vector3(_X, _Y, _Z);}


protected:
	//is_controll is 0 if it is already doing something
	//else 1
	int is_controll;

	bool direction;

	int max_hp;
	int hp;
	int state;

	Image* pImage;  //이미지포인터
	Vector3 position; // Make Getter Setter
	Vector3 velocity; // Make Getter Setter

};

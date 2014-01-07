#include "XDSprite.h"

void XDSprite :: drawSprite( Graphics& G ){

}
void XDSprite :: update(int dt){
}
	
XDSprite::XDSprite( ) {
	is_controll = 1;
	max_hp = 1;
	hp = 1;
	state = 0; //??
	position = Vector3(0,0,0);
	velocity = Vector3(10,10,10);
}

XDSprite :: XDSprite(wstring _Path){
	pImage = new Image(_Path.c_str() ); //ResManager :: addImage( _Path );
	position.X = 100;
	position.Y = 0;
	position.Z = 100;
	velocity.X = 1;
	velocity.Y = 1;
	velocity.Z = 1;
}

/*
XDSprite :: XDSprite(int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity) {
	direction = true;
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

XDSprite :: XDSprite(int _Controll, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity) {
	direction = true;
	is_controll = _Controll;
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

XDSprite :: XDSprite(int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
	direction = true;
	is_controll = 1;
	max_hp = _MaxHP;
	hp = _HP;
	state = 0; //??
	position = Vector3(_PosX, _PosY, _PosZ);
	velocity = Vector3(_VelZ, _VelY, _VelZ);
}

XDSprite :: XDSprite(int _Controll, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
	direction = true;
	is_controll = _Controll;
	max_hp = _MaxHP;
	hp = _HP;
	state = 0; //??
	position = Vector3(_PosX, _PosY, _PosZ);
	velocity = Vector3(_VelZ, _VelY, _VelZ);
}



XDSprite :: XDSprite(bool _Direction, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity) {
	direction = _Direction;
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

XDSprite :: XDSprite(bool _Direction, int _Controll, int _MaxHP, int _HP, const Vector3& _Position, const Vector3& _Velocity) {
	direction = _Direction;
	is_controll = _Controll;
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

XDSprite :: XDSprite(bool _Direction, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
	direction = _Direction;
	is_controll = 1;
	max_hp = _MaxHP;
	hp = _HP;
	state = 0; //??
	position = Vector3(_PosX, _PosY, _PosZ);
	velocity = Vector3(_VelZ, _VelY, _VelZ);
}

XDSprite :: XDSprite(bool _Direction, int _Controll, int _MaxHP, int _HP, int _PosX, int _PosY, int _PosZ, int _VelX, int _VelY, int _VelZ) {
	direction = _Direction;
	is_controll = _Controll;
	max_hp = _MaxHP;
	hp = _HP;
	state = 0; //??
	position = Vector3(_PosX, _PosY, _PosZ);
	velocity = Vector3(_VelZ, _VelY, _VelZ);
}
*/


XDSprite::~XDSprite(void)
{
	//..?
}


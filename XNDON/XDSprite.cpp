#include "XDSprite.h"

void XDSprite :: drawSprite( Graphics& G ){

}
void XDSprite :: update(int dt){
}
	
XDSprite::XDSprite( ){
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
	position.Z = 0;
	velocity.X = 1;
	velocity.Y = 1;
	velocity.Z = 1;
}

XDSprite::~XDSprite(void)
{
	//..?
}


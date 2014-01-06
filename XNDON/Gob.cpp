#include "Gob.h"


void Gob :: drawSprite(Graphics& G){
	G.DrawImage( pImage, position.X, position.Y, 0, 0, pImage->GetWidth(), pImage->GetHeight(), Gdiplus::UnitPixel);
}

void Gob :: update(int dt)
{
	lookat(plpos);
	move(dt/7);
	
}
Gob::Gob(void)
	: Sprite(L"./goblin_default.png")
{
	position = Vector3(640, 100, 0);
	velocity = Vector3(1, 1, 0);
}

Gob::Gob(const Vector3 &PlayerPos)
	: Sprite(L"./goblin_default.png")
{
	position = Vector3(640, 720, 0);
	velocity = Vector3(1, 1, 0);
	plpos = PlayerPos;
}

void Gob :: lookat(Vector3 v3){
	
	velocity =(v3 - position);
	velocity.X = (velocity.X==0)? 0 : velocity.X/(abs(velocity.X));
	velocity.Y = (velocity.Y==0)? 0 : velocity.Y/(abs(velocity.Y));
	velocity.Z = (velocity.Z==0)? 0 : velocity.Z/(abs(velocity.Z));
	 
}

void Gob :: setplpos(const Vector3& v3){
	plpos = v3;
}

Gob::~Gob(void)
{
}

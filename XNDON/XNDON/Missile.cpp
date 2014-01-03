#include "Missile.h"


void Missile :: drawSprite(Graphics& G){
	G.DrawImage( pImage, position.X, position.Y, 0, 0, pImage->GetWidth(), pImage->GetHeight(), Gdiplus::UnitPixel);
}

void Missile :: update(int dt)
{
	moveLeft(dt/10);

}
Missile::Missile(void)
	: Sprite(L"./Fire.png")
{
	position = Vector3(1280, 0, 240);
	velocity = Vector3(1, 0, 0);
}


Missile::~Missile(void)
{
}

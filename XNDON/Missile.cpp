#include "Missile.h"
#include<cmath>

void Missile :: drawSprite(Graphics& G){
	G.DrawImage( pImage, position.X, position.Y, 0, 0, pImage->GetWidth(), pImage->GetHeight(), Gdiplus::UnitPixel);
}

void Missile :: update(int dt)
{

	position.X -= velocity.X * dt/7;

	position.Y += 10 * velocity.Y;
	if(position.Y > 760 - pImage->GetHeight()) {
		velocity.Y = -velocity.Y;
	}
	else if(position.Y < -20) {
		velocity.Y = -velocity.Y;
	}
	if(position.X < -30) {
		position.X = 1280;
	}

}

Missile::Missile(void)
	: XDSprite(L"./Fire.png")
{
	position = Vector3(1280, 100, 480);
	velocity = Vector3(1, 1, 0);
}


Missile::~Missile(void)
{


}

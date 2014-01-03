#include "Gob.h"


Gob::Gob(void) : Sprite(L"./goblin_default.png")
{
	position = Vector3(1280, 0, 340);
	velocity = Vector3(1, 0, 0);
}


Gob::~Gob(void)
{
}

void Gob :: drawSprite(Graphics& G){
	G.DrawImage( pImage, position.X, position.Y, 0, 0, pImage->GetWidth(), pImage->GetHeight(), Gdiplus::UnitPixel);
}

void Gob :: update(int dt)
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

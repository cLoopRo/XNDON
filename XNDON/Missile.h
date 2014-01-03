#pragma once
#include "sprite.h"
class Missile :
	public Sprite
{
public:
	Missile(void);
	void update(int dt);
	void drawSprite(Graphics& G);
	virtual ~Missile(void);
private:
};


#pragma once
#include "sprite.h"
#include<cmath>

class Gob :
	public Sprite
{
public:
	Gob(void);
	void update(int dt);
	void drawSprite(Graphics& G);
	virtual ~Gob(void);

};


#pragma once
#include "XDSprite.h"
class Missile :
	public XDSprite
{
public:
	Missile(void);
	void update(int dt);
	void drawSprite(Graphics& G);
	virtual ~Missile(void);
private:
};

